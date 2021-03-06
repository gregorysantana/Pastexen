Pastexen
=========

Утилита для быстрой загрузки скриншотов и исходного кода на сервер. По нажатию хоткея (F11) делается скриншот, загружается на сервер, публикуется, в буфер обмена копируется ссылка.

### Информация
* Скачать для [Windows](https://github.com/bakwc/Pastexen/raw/master/builds/pastexen_v2_win32_installer.exe), [MacOS](https://github.com/bakwc/Pastexen/raw/master/builds/pastexen_v2_mac_beta_2.tar.gz) или [Linux](https://github.com/bakwc/Pastexen/raw/master/builds/pastexen_v2_i386.deb) (deb)
* Описание архитектуры: [читать](https://github.com/bakwc/Pastexen/wiki)
* Исходники: [скачать](https://github.com/bakwc/Pastexen/zipball/master)

### Использование
* При первом запуске выберите формат файла картинок (jpg / png) и язык программирования (для правильного подсветки синтаксиса)
* F11 - программа сделает скриншот всего экрана, скопирует в буфер обмена прямую ссылку на изображение
* F10 - скриншот части экрана (необходимо выделить мышкой часть экрана)
* F9 - публикация текстов/исходников. Выделите текст и нажмите на F9. Вы получите ссылку на ваш текст/исходник с подсветкой синтаксиса для выбранного языка программирования

### Сборка // Build
* Install [Qt 5.2.0](http://qt-project.org/downloads)
* Windows,Linux build required GCC 4.7.2 or Clang 3.2.5
* Linux build required libxcb and libxcb-keysyms
* [NSIS 3](http://nsis.sourceforge.net) required for compiling installation script
* git clone git@github.com:bakwc/Pastexen
* cd Pastexen
* qmake
* make
* make install

### Лицензия
GNU GPL v3, http://www.gnu.org/licenses/gpl.html
