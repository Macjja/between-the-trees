/* Implementation of the Scene class */

#include "dialogue.h"

using namespace std;

Dialogue::Dialogue(ResourceLoader* data)
{
    state = 0;
    currentLine = 0;
    currentChar = 0;
    name = "";
    showName = false;
    
    font = data.get_font();
    textContainer = data.get_text_container();
    nameContainer = data.get_name_container();
}
Dialogue::Dialogue(ResourceLoader* data, string name)
{
    state = 0;
    currentLine = 0;
    currentChar = 0;
    name = name;
    showName = true;
    
    font = data.font;
    textContainer = data.img_textContainer;
    nameContainer = data.img_nameContainer;
}

Dialogue::draw(int y) const
{
    al_draw_bitmap(textContainer, 0, y, 0);
    
    if (showName)
    {
        al_draw_bitmap(nameContainer, 0, y - 10, 0);
        al_draw_text(font, al_map_rgb(255, 255, 255), 2, y - 8, 0, name.c_str());
    }
    
    string str = text[currentLine];
    int write_y = y + 2;
    int start = 0;
    int end = str.find('\n');
    if (end == -1)
        end = str.length();
    
    while (start < str.length())
    {
        if (state == 0 && currentChar < end)
        {
            al_draw_text(font, al_map_rgb(255, 255, 255), 2, write_y, 0, str.substr(start, currentChar - start + 1).c_str());
            break;
        }
        else
        {
            al_draw_text(font, al_map_rgb(255, 255, 255), 2, write_y, 0, str.substr(start, end - start).c_str());
            start = end + 1;
            end = str.find('\n', start);
            if (end == -1)
                end = str.length();
            write_y += 8;
        }
    }
}

bool& Dialogue::get_state()
{
    return state;
}
void Dialogue::set_text(string str)
{
    text.push_back(str);
}
vector<string>& Dialogue::get_text()
{
    return text;
}
bool Dialogue::next_line()
{
    currentLine++;
    if (currentLine >= text.size())
        return false;
    return true;
}
string Dialogue::get_current_line() const
{
    return text[currentLine];
}
bool Dialogue::next_char()
{
    currentChar++;
    if (currentChar >= text[currentLine].size())
    {
        currentChar = 0;
        return false;
    }
    return true;
}
char Dialogue::get_current_char() const
{
    return text[currentLine][currentChar];
}
void Dialogue::set_name(string str)
{
    name = str;
}
string Dialogue::get_name() const
{
    return name;
}
bool& Dialogue::show_name()
{
    return showName;
}