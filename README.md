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
Класс кнопки. Создаёт объект имеющий форму(круг или прямуогольник), способный
проверять состояние и вызывать задекларированные функции callback 

- push_mod(); *released и oneclick*
- callback(); *подобно FLTK*
- when_pushing(); *callback но постоянно вызывающийся*
- hover_effects(); *отображения эффектов наводки*

#### CALLBACK и WHEN_PUSH пояснение
В кнопку с помощью `obj.callback()` можно передавать свою функцию.
Для этого нужно заранее объявить функцию типа void. Она сама будет вызываться в Event.
Функцию `obj.when_push()` необходимо использовать в основном цикле. Это необходимо для
корректной работы кнопок.

```cpp
#include "SGUI.hpp"

void foo()
{ std::cout << "it's work!"; }

int main()
{
  sf::RenderWindow window(sf::VideoMode({ 900, 800 }), "SFML works!");

  Button b(shape_type::rectangle, L"КНОПКА");
  b.push_mod(push_type::oneclick);
  b.callback(foo);  // передаем свою функцию в кнопку

  while(window.isOpen())
  {
    
    b.cursor_position(window); // передаем позицию курсора объекту
    while ( const std::optional event = window.pollEvent() )
    {
    	if ( event->is<sf::Event::Closed>() )window.close();
		    b.event(event); // здесь вызывается foo() при нажатии ЛКМ
    }

    b.when_push(foo); //будет вызывать foo() каждый кадр, когда нажата

      //.. остальной код
  }
  
}
```

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
