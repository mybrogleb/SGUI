## Полный список методов Button

| Метод | Описание | Пример |
| :--- | :--- | :--- |
| **Конструкторы** |||
| `Button(shape_type type)` | Создаёт кнопку с указанной формой (`rectangle` или `circle`). Размер и позиция по умолчанию. | `Button btn(shape_type::rectangle);` |
| `Button(shape_type type, std::wstring text)` | Создаёт кнопку с формой и текстом. | `Button btn(shape_type::circle, L"OK");` |
| **Настройка вида** |||
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
| `void text(sf::Text::Style& style)` | Устанавливает стиль текста (жирный, курсив и т.д.). | `btn.text(sf::Text::Bold);` |
| `void text(sf::Font& font)` | Устанавливает шрифт для текста. | `btn.text(myFont);` |
| **Поведение и события** |||
| `void push_mod(push_type type)` | Устанавливает режим нажатия (`oneclick` или `released`). | `btn.push_mod(push_type::oneclick);` |
| `void callback(std::function<void()> func)` | Устанавливает функцию для однократного вызова при клике. | `btn.callback(myFunc);` |
| `void when_pushing(std::function<void()> func)` | Устанавливает функцию для вызова каждый кадр, пока кнопка зажата. | `btn.when_pushing(myFunc);` |
| `void hover_effects()` | Включает визуальные эффекты при наведении (цвет, граница). | `btn.hover_effects();` |
| **Служебные** |||
| `void cursor_position(sf::RenderWindow& window)` | Передаёт позицию курсора для обработки наведения. | `btn.cursor_position(window);` |
| `void event(const std::optional<sf::Event>& event)` | Передаёт событие SFML в кнопку. | `btn.event(event);` |
| **Геттеры** |||
| `std::optional<sf::Text>& text()` | Возвращает ссылку на объект `sf::Text` для прямого доступа (если он есть). | `auto& txt = btn.text();` |
| `sf::Color color()` | Возвращает текущий цвет кнопки. | `sf::Color c = btn.color();` |
| `sf::Color hover_color()` | Возвращает цвет кнопки при наведении. | `sf::Color c = btn.hover_color();` |
| `sf::Color border_color()` | Возвращает цвет границы. | `sf::Color c = btn.border_color();` |
| `sf::Vector2f size()` | Возвращает размер кнопки. | `auto sz = btn.size();` |
| `sf::Vector2f position()` | Возвращает позицию кнопки. | `auto pos = btn.position();` |
| `sf::Vector2f button_origin()` | Возвращает точку отсчёта (origin) кнопки. | `auto origin = btn.button_origin();` |
| `sf::Vector2f button_center()` | Возвращает координаты центра кнопки. | `auto center = btn.button_center();` |

## Полный список методов Label

| Метод | Описание | Пример |
| :--- | :--- | :--- |
| **Конструкторы** |||
| `Label(std::wstring str)` | Создаёт лейбл с указанным текстом. | `Label title(L"Заголовок");` |
| `Label()` | Создаёт лейбл с текстом-заглушкой `SOME TEXT`. | `Label defaultLabel;` |
| **Настройка текста** |||
| `void text(std::wstring str)` | Устанавливает текст лейбла. | `label.text(L"Привет!");` |
| `void text(sf::Color color)` | Устанавливает цвет текста. | `label.text(sf::Color::Red);` |
| `void text(int size)` | Устанавливает размер шрифта (кегль). | `label.text(24);` |
| `void text(sf::Text::Style& style)` | Устанавливает стиль текста (жирный, курсив и т.д.). | `label.text(sf::Text::Bold);` |
| `void text(sf::Font& font)` | Устанавливает шрифт для текста. | `label.text(myFont);` |
| **Настройка фона** |||
| `void background(bool enable)` | Включает (`true`) или выключает (`false`) отображение фона. | `label.background(true);` |
| `void background(sf::Color color)` | Устанавливает цвет фона. | `label.background(sf::Color::Blue);` |
| `void background(float margin)` | Устанавливает одинаковые отступы (поля) вокруг текста. | `label.background(10);` |
| `void background(float marginX, float marginY)` | Устанавливает отдельные отступы по горизонтали и вертикали. | `label.background(20, 5);` |
| **Позиционирование** |||
| `void position(float x, float y)` | Устанавливает позицию лейбла на экране (верхний левый угол текста). | `label.position(100, 200);` |
| **Геттеры** |||
| `std::optional<sf::Text>& text()` | Возвращает ссылку на объект `sf::Text` для прямого доступа (если он есть). | `auto& txt = label.text();` |
| `sf::RectangleShape& shape()` | Возвращает ссылку на объект фона `sf::RectangleShape`. | `auto& bg = label.shape();` |
