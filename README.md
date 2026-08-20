# SIMPLE GUI для SFML
Этот репозиторий разработан для упрощения работы с SFML. Основная идея: простота и гибкость. 
Синтаксис похож на FLTK. Проект представляет из себя файлы .hpp и ресурсы.
Для начала работы с фреймворком достаточно просто добавить файлы в свой проект, где ваш main.hpp . Для шрифтов есть директория
/bin/Debug/assets/fonts. 

- для корректного отображения кириллицы, установите кодировку UTF-8 with BOM
- для корректного запуска назначьте файл SGUI или свой main в качестве запускаемого проекта
- для корректной отладки в Visual Studio, в свойствах проекта -> конфигурация -> отладка -> рабочий каталог : измените на "$(TargetDir)"

> CMake автоматически создаст все директории и скопирует туда необходимые ресурсы

> Config.hpp содержит константы и загружает базовый шрифт

# ВОЗМОЖНОСТИ 20.08.2026
## Классы:
- Widget (абстрактный класс)
- Button (кнопка)
- Label (однострочный ярлык/текст)
  
### Button
*кроме основных методов оформления и переопределенных методов widget*

- push_mod(); <small>released и oneclick</small>
- callback(); <small>подобно FLTK</small>
- when_pushing(); <small>callback но постоянно вызывающийся</small>
- hover_effects(); <small>отображения эффектов наводки</small>

### Label
Класс однострочного текста с ярлыком(может отсутствовать)
Автоматически выравнивает текст внутри ярлыка.

## More Reading

Here are some useful resources if you want to learn more about CMake:

- [Official CMake Tutorial](https://cmake.org/cmake/help/latest/guide/tutorial/)
- [How to Use CMake Without the Agonizing Pain - Part 1](https://alexreinking.com/blog/how-to-use-cmake-without-the-agonizing-pain-part-1.html)
- [How to Use CMake Without the Agonizing Pain - Part 2](https://alexreinking.com/blog/how-to-use-cmake-without-the-agonizing-pain-part-2.html)
- [Better CMake YouTube series by Jefferon Amstutz](https://www.youtube.com/playlist?list=PL8i3OhJb4FNV10aIZ8oF0AA46HgA2ed8g)

## License

The source code is dual licensed under Public Domain and MIT -- choose whichever you prefer.
