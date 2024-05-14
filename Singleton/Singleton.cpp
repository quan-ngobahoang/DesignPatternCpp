#include <iostream>
#include <string>

using namespace std;

class GameSetting
{
private:
    static GameSetting *_instance;
    int _brightness;
    int _width;
    int _height;

public:
    static GameSetting *getInstance()
    {
        if (_instance == nullptr)
        {
            _instance = new GameSetting();
        }
        return _instance;
    }

    void setWidth(int width)
    {
        _width = width;
    }

    void setHeight(int height)
    {
        _height = height;
    }

    void setBrightness(int brightness)
    {
        _brightness = brightness;
    }

    int getWidth()
    {
        return _width;
    }

    int getHeight()
    {
        return _height;
    }

    int getBrightness()
    {
        return _brightness;
    }

    void displaySetting()
    {
        cout << "brightness: " << _brightness << endl;
        cout << "width: " << _width << endl;
        cout << "height: " << _height << endl;
    }
};

GameSetting *GameSetting::_instance = nullptr;

int main(int argc, char *argv[])
{
    GameSetting *gameSettings = GameSetting::getInstance();
    gameSettings->setBrightness(100);
    gameSettings->setHeight(60);
    gameSettings->setWidth(50);
    gameSettings->displaySetting();
    return 0;
}