#include "ukeysequence.h"

#include <QDebug>

UKeySequence::UKeySequence(QObject *parent)
    : QObject(parent)
{
}

UKeySequence::UKeySequence(const QString& str, QObject *parent)
    : QObject(parent)
{
    FromString(str);
}

bool IsModifier(int key) {
    return (key == Qt::Key_Shift ||
            key == Qt::Key_Control ||
            key == Qt::Key_Alt);
}

static QString KeyToStr(int key) {
    if (key == Qt::Key_Shift) {
        return "Shift";
    }
    if (key == Qt::Key_Control) {
        return "Ctrl";
    }
    if (key == Qt::Key_Alt) {
        return "Alt";
    }
    QKeySequence seq(key);
    return seq.toString();
}

void UKeySequence::FromString(const QString& str) {
    QStringList keys = str.split('+');
    for (int i = 0; i < keys.size(); i++) {
        AddKey(keys[i]);
    }
}

QString UKeySequence::ToString() {
    QVector<int> simpleKeys = GetSimpleKeys();
    QVector<int> modifiers = GetModifiers();
    QStringList result;
    for (int i = 0; i < modifiers.size(); i++) {
        result.push_back(KeyToStr(modifiers[i]));
    }
    for (int i = 0; i < simpleKeys.size(); i++) {
        result.push_back(KeyToStr(simpleKeys[i]));
    }
    return result.join('+');
}

QVector<int> UKeySequence::GetSimpleKeys() {
    QVector<int> result;
    for (int i = 0; i < Keys.size(); i++) {
        if (!IsModifier(Keys[i])) {
            result.push_back(Keys[i]);
        }
    }
    return result;
}

QVector<int> UKeySequence::GetModifiers() {
    QVector<int> result;
    for (int i = 0; i < Keys.size(); i++) {
        if (IsModifier(Keys[i])) {
            result.push_back(Keys[i]);
        }
    }
    return result;
}

void UKeySequence::AddModifiers(Qt::KeyboardModifiers mod) {
    if (mod == Qt::NoModifier) {
        return;
    }
    if (mod & Qt::ShiftModifier) {
        AddKey(Qt::Key_Shift);
    }
    if (mod & Qt::ControlModifier) {
        AddKey(Qt::Key_Control);
    }
    if (mod & Qt::AltModifier) {
        AddKey(Qt::Key_Alt);
    }
}

void UKeySequence::AddKey(const QString& key) {
    if (key.contains("+") || key.contains(",")) {
        throw UException("Wrong key");
    }

    QString mod = key.toLower();
    if (mod == "alt") {
        AddKey(Qt::Key_Alt);
        return;
    }
    if (mod == "shift" || mod == "shft") {
        AddKey(Qt::Key_Shift);
        return;
    }
    if (mod == "control" || mod == "ctrl") {
        AddKey(Qt::Key_Control);
        return;
    }
    QKeySequence seq(key);
    if (seq.count() != 1) {
        throw UException("Wrong key");
    }
    AddKey(seq[0]);
}

void UKeySequence::AddKey(int key) {
    if (key <= 0) {
        return;
    }
    for (int i = 0; i < Keys.size(); i++) {
        if (Keys[i] == key) {
            return;
        }
    }
    Keys.push_back(key);
}

void UKeySequence::AddKey(const QKeyEvent* event) {
    AddKey(event->key());
    AddModifiers(event->modifiers());
}