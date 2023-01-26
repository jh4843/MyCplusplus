#include <iostream>
#include <memory>

using namespace std;

class Song {
    string m_strTitle;
    string m_strSinger;

public:
    wstring m_wsDuration;

public:
    Song(string title, string singer)
    {
        m_strTitle = title;
        m_strSinger = singer;

        m_wsDuration = L"0";
    }
};

void UseRawPointer()
{
    // Using a raw pointer -- not recommended.
    Song* pSong = new Song("Nothing on You"s, "Bruno Mars"s);

    // Use pSong...

    // Don't forget to delete!
    delete pSong;
}


void UseSmartPointer()
{
    // Declare a smart pointer on stack and pass it the raw pointer.
    unique_ptr<Song> song2(new Song("Nothing on You"s, "Bruno Mars"s));

    // Use song2...
    wstring s = song2->m_wsDuration;
    //...

} // song2 is deleted automatically here.

void main()
{
    UseRawPointer();

    UseSmartPointer()
}