#include <SFML/Graphics.hpp>

#include <cstdlib>
#include <ctime>
#include <fstream>


int N = 30, M = 20;
int size = 20;

int dir, num = 4;

int cur_line = 0;

struct Snake
{
    int x, y;
} s[100];

struct Fruit
{
    int x, y;
} f;

void Tick()
{
    for (int i = num; i > 0; --i) {
        s[i].x = s[i - 1].x;
        s[i].y = s[i - 1].y;
    }

    if (dir == 0) s[0].y += 1;
    if (dir == 1) s[0].x -= 1;
    if (dir == 2) s[0].x += 1;
    if (dir == 3) s[0].y -= 1;

    if ((s[0].x == f.x) && (s[0].y == f.y)) {
        num++;
        f.x = std::rand() % N;
        f.y = std::rand() % M;
    }

    if (s[0].x > N) s[0].x = 0;
    if (s[0].x < 0) s[0].x = N;
    if (s[0].y > M) s[0].y = 0;
    if (s[0].y < 0) s[0].y = M;

    for (int i = 1; i < num; i++) if (s[0].x == s[i].x && s[0].y == s[i].y) exit(0);
}

int main()
{
    std::srand(time(0));

    sf::RenderWindow window(sf::VideoMode(size * N, size * M), "Snake Game!");

    sf::RectangleShape sprite1(sf::Vector2f(size - 0.5, size - 0.5));
    sprite1.setFillColor(sf::Color::Black);
    sf::RectangleShape sprite2(sf::Vector2f(size, size));
    sprite2.setFillColor(sf::Color::Red);

    sf::Clock clock;
    float timer = 0, delay = 0.1;

    f.x = 10;
    f.y = 10;

    while (window.isOpen())
    {
        timer += clock.getElapsedTime().asSeconds();;
        clock.restart();

        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) window.close();
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) dir = 1;
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) dir = 2;
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) dir = 3;
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) dir = 0;

        std::ifstream reader("interface.txt");
        std::string line;

        int i = 0;

        while (getline(reader, line)) {
            if (cur_line == i) {
                if (line == "Left") dir = 1;
                else if (line == "Right") dir = 2;
                else if (line == "Up") dir = 3;
                else if (line == "Down") dir = 0;
            }
            
            i++;
        }

        if (timer > delay) {
            timer = 0;
            Tick();
        }

        window.clear(sf::Color::White);

        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                sprite1.setPosition(i * size, j * size);
                window.draw(sprite1);
            }
        }

        for (int i = 0; i < num; i++) {
            sprite2.setPosition(s[i].x * size, s[i].y * size);
            window.draw(sprite2);
        }

        sprite2.setPosition(f.x * size, f.y * size);
        window.draw(sprite2);

        window.display();
    }

    return 0;
}
