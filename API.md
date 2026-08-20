## Полный список методов Button

| Метод | Описание | Пример |
| :--- | :--- | :--- |
| `void size(float x, float y)` | Устанавливает размер (ширина, высота). Для круга `x` — диаметр. | `btn.size(100, 50);` |
| `void size(float x)` | Устанавливает размер для круга (диаметр) или квадрата (сторона). | `btn.size(100);` |
| `void position(float x, float y)` | Устанавливает позицию на экране. | `btn.position(200, 100);` |
| `void color(sf::Color color)` | Устанавливает основной цвет кнопки. | `btn.color(sf::Color::Blue);` |
| `void hover_color(sf::Color color)` | Устанавливает цвет кнопки при наведении мыши. | `btn.hover_color(sf::Color::Red);` |
| `void border(border_type type, float size, sf::Color color)` | Устанавливает границу (`fixed` — всегда, `hover` — при наведении). | `btn.border(border_type::hover, 3, sf::Color::Black);` |
| `void scale(sf::Vector2f scale)` | Масштабирует кнопку. | `btn.scale({1.5f, 1.5f});` |
| `void origin(origin_type type)` | Устанавливает точку отсчёта (`center` или `angle`). | `btn.origin(origin_type::center);` |
| **Работа с текстом** |||
| `void text(std::wstring str)` | Устанавливает текст на кнопке. | `btn.text(L"OK");` |
| `void text(sf::Color color)` | Устанавливает цвет текста. | `btn.text(sf::Color::White);` |
| `void text(int size)` | Устанавливает размер шрифта. | `btn.text(24);` |
| **Поведение и события** |||
| `void push_mod(push_type type)` | Устанавливает режим нажатия (`oneclick` или `released`). | `btn.push_mod(push_type::oneclick);` |
| `void callback(std::function<void()> func)` | Устанавливает функцию для однократного вызова при клике. | `btn.callback(myFunc);` |
| `void when_pushing(std::function<void()> func)` | Устанавливает функцию для вызова каждый кадр, пока кнопка зажата. | `btn.when_pushing(myFunc);` |
| `void hover_effects()` | Включает визуальные эффекты при наведении (цвет, граница). | `btn.hover_effects();` |
| **Служебные** |||
| `void cursor_position(sf::RenderWindow& window)` | Передаёт позицию курсора для обработки наведения. | `btn.cursor_position(window);` |
| `void event(const std::optional<sf::Event>& event)` | Передаёт событие SFML в кнопку. | `btn.event(event);` |
| **Геттеры** |||
| `sf::Vector2f size()` | Возвращает размер кнопки. | `auto sz = btn.size();` |
| `sf::Color color()` | Возвращает текущий цвет кнопки. | `sf::Color c = btn.color();` |
