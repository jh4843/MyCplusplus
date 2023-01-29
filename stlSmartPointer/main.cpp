#include <iostream>
#include <memory>
#include <vector>
#include <algorithm>

using namespace std;

class Song {

public:
    string m_strTitle;
    string m_strSinger;

    wstring m_wsDuration;

    vector<weak_ptr<Song>> others;

public:
    Song(string title, string singer)
    {
        m_strTitle = title;
        m_strSinger = singer;

        m_wsDuration = L"0";
    }

    ~Song() {
        cout << "Destroying Song: " << m_strTitle << endl;
    }

    void CheckSongList() const
    {
        for_each(others.begin(), others.end(), [](weak_ptr<Song> wp) 
        {
            auto p = wp.lock();
            if (p)
            {
                cout << "Singer of " << p->m_strTitle << ": " << p->m_strSinger << endl;
            }
            else
            {
                cout << "Null object" << endl;
            }
        });
    }
};

void UseRawPointer()
{
    cout << "UseRawPointer()" << endl;

    // Using a raw pointer -- not recommended.
    Song* pSong = new Song("Nothing on You"s, "Bruno Mars"s);

    // Use pSong...
    
    // Need to delete 
    delete pSong;
}

void UseUniquePointer()
{
    cout << "UseUniquePointer()" << endl;
    
    // #1. Create instance: normally 
    unique_ptr<Song> song2(new Song("Nothing on You"s, "Bruno Mars"s));

    // #2. Create instance: Use helper function - recommended
    unique_ptr<Song> song3 = make_unique<Song>("Hey~"s, "Denv"s);
    cout << "song3: " << song3 << '\t' << typeid(song3).name() << endl;
    // Move ownership to unique_ptr(song4) from song3
    unique_ptr<Song> song4 = move(song3);
    cout << "song4: " << song4 << '\t' << typeid(song4).name() << endl;

    if (song3)
    {
        cout << "song3 is not empty" << endl;
    }

    // Move ownership to raw pointer(song5) from song4
    Song* song5 = song4.release();
    cout << "song5: " << song4 << '\t' << typeid(song5).name() << endl;

    if (song4)
    {
        cout << "song3 is not empty" << endl;
    }

    // Need to release memory of song5
    delete song5;
} 

void UseSharedPointer()
{
    cout << "UseSharedPointer()" << endl;

    // #1. Create instance: normally 
    shared_ptr<Song> song1(new Song("Nothing on You"s, "Bruno Mars"s));
    cout << "song1: " << song1->m_strTitle << '\t' << typeid(song1).name() << endl;

    // #2. Create instance: Use helper function - recommended
    shared_ptr<Song> song2 = make_shared<Song>("Hey~"s, "Denv"s);
    cout << "song2: " << song2->m_strTitle << '\t' << typeid(song2).name() << endl;

    // #3. Copy
    shared_ptr<Song> song3(song2);
    cout << "song3: " << song3->m_strTitle << '\t' << typeid(song3).name() << "Ref Count: " << song3.use_count() << endl;
    shared_ptr<Song> song4 = song2;
    cout << "song3: " << song4->m_strTitle << '\t' << typeid(song4).name() << "Ref Count: " << song4.use_count() << endl;
    
    // #4. Swap
    song2.swap(song1);
    cout << "song1: " << song1->m_strTitle << '\t' << typeid(song1).name() << "Ref Count: " << song1.use_count() << endl;
    cout << "song2: " << song2->m_strTitle << '\t' << typeid(song2).name() << "Ref Count: " << song2.use_count() << endl;
    cout << "song3: " << song3->m_strTitle << '\t' << typeid(song3).name() << "Ref Count: " << song3.use_count() << endl;
}

void UseWeakPointer()
{
    cout << "UseWeakPointer()" << endl;

    vector<shared_ptr<Song>> vecSongs{
        make_shared<Song>("Hey~"s, "Denv"s),
        make_shared<Song>("Monologue"s, "Tei"s),
        make_shared<Song>("Tears"s, "So"s),
        make_shared<Song>("Delete"s, "Lee"s),
        make_shared<Song>("Hello Carbot"s, "Satan"s),
    };

    for (int i = 0; i < vecSongs.size(); ++i)
    {
        for_each(vecSongs.begin(), vecSongs.end(), [&vecSongs, i](shared_ptr<Song> p) 
        {
            if (p->m_strTitle != vecSongs[i]->m_strTitle)
            {
                vecSongs[i]->others.push_back(weak_ptr<Song>(p));
                cout << "push_back to vecSongs[" << i << "]: " << p->m_strTitle << endl;
            }
        });
    }

    for_each(vecSongs.begin(), vecSongs.end(), [](shared_ptr<Song>& p)
    {
        wcout << L"use_count = " << p.use_count() << endl;
        p->CheckSongList();
    });
}

int main()
{
    // Rwa Pointer
    UseRawPointer();

    // Smart Pointer
    UseUniquePointer();
    UseSharedPointer();
    UseWeakPointer();
    return 0;
}