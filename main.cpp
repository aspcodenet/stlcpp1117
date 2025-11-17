#include <iostream>
#include <string>
#include <vector>
#include <array>
#include <algorithm>
#include <numeric>

class Movie{
public:
    typedef enum {
        MovieType_Film,
        MovieType_Tv
    }MovieType;

    Movie(std::string name, int year,MovieType type){
        this->name = name;
        this->year = year;
        this->type = type;
    }
    std::string getName() const{
        return name;
    }
    int getYear() const{
        return year;
    }
    MovieType getMovieType() const{
        return type;
    }
private:
    std::string name;
    MovieType type;
    int year;
};



// DEFINE = preprocessorn - FATTAR INTE C/C++ ren TEXT
// #define BIT_SET(a,b) (dasdaasd,asdasdasd)

// DATASTRUKTURER = hur kan man skapa DS som funkar med "vad som helst" int, HockeyPlayer
// ALGORITMER - hur kan man återanvända en algoritm med "vad som helst" int, float, string

// D.R.Y



// int findBiggest(int i,int j,int k){
//     if(i > j && i > k){
//         return i;
//     }
//     if(j > i && j > k){
//         return j;
//     }
//     return k; 
// }

// float findBiggest(float i,float j,float k){
//     if(i > j && i > k){
//         return i;
//     }
//     if(j > i && j > k){
//         return j;
//     }
//     return k; 
// }

// std::string findBiggest(std::string i,std::string j,std::string k){
//     if(i > j && i > k){
//         return i;
//     }
//     if(j > i && j > k){
//         return j;
//     }
//     return k; 
// }


template <typename T>
T findBiggest(T i,T j,T k){
    if(i > j && i > k){
        return i;
    }
    if(j > i && j > k){
        return j;
    }
    return k; 
}



template<typename T,int N>
class MyArray{
public: 
    MyArray(){
        antal = 0;
    }
    void add(T one){
        // om antalet > max 
        // return "ERROR - finns inte plats för mer"
        // 
        things[antal] = one;
        antal++;
    }
    int size(){
        return antal;
    }
    T getAt(int index){
        return things[index];
    }


private:
    int antal;
    T things[N]; // KAN INTE VÄXA/KRYMPA .- statisk i storlek  , INTE static
};





int main(){ 
    MyArray<int,120> ages;
    MyArray<std::string,2> namn;
    int tal1 = 12; 
    int tal2 = 13;
    int tal3 = 4; // Tänk er att man matar in
    int biggest = findBiggest<int>(tal1,tal2,tal3);

    float tal1f = 12.0f; 
    float tal2f = 13.0f;
    float tal3f = 12.3f; // Tänk er att man matar in
    float biggestf = findBiggest<float>(tal1f,tal2f,tal3f);

    std::string namn1 = "Anna"; 
    std::string namn2 = "Stefan"; 
    std::string namn3 = "Kalle"; 
    std::string na = findBiggest<std::string>(namn1,namn2,namn3);



    // Skriv en funktion som tar fram det STÖRSTA talet - ALGORITM (!)
    std::cout << "Hej" << tal1 << tal2 << tal3  << std::endl;


    std::vector<int> test = {12,1222,32234,434};
    

    std::vector<Movie> greatMovies{
        Movie("The Mummy returns",2001,Movie::MovieType::MovieType_Film),
        Movie("Fast and Furious 7",2014,Movie::MovieType::MovieType_Film),
        Movie("Fast & Furious Presents: Hobbs & Shaw",2019,Movie::MovieType::MovieType_Film),
        Movie("Young Rock",2021,Movie::MovieType::MovieType_Tv),
        Movie("The Scorpion King", 2002, Movie::MovieType::MovieType_Film),
        Movie("Welcome to the Jungle", 2003, Movie::MovieType::MovieType_Film),
        Movie("Walking Tall", 2004, Movie::MovieType::MovieType_Film),
        Movie("Be Cool", 2005, Movie::MovieType::MovieType_Film),
        Movie("Doom", 2005, Movie::MovieType::MovieType_Film),
        Movie("Gridiron Gang", 2006, Movie::MovieType::MovieType_Film),
        Movie("The Game Plan", 2007, Movie::MovieType::MovieType_Film),
        Movie("Get Smart", 2008, Movie::MovieType::MovieType_Film),
        Movie("Race to Witch Mountain", 2009, Movie::MovieType::MovieType_Film),
        Movie("Tooth Fairy", 2010, Movie::MovieType::MovieType_Film),
        Movie("Fast Five", 2011, Movie::MovieType::MovieType_Film),
        Movie("Journey 2: The Mysterious Island", 2012, Movie::MovieType::MovieType_Film),
        Movie("G.I. Joe: Retaliation", 2013, Movie::MovieType::MovieType_Film),
        Movie("Hercules", 2014, Movie::MovieType::MovieType_Film),
        Movie("San Andreas", 2015, Movie::MovieType::MovieType_Film),
        Movie("Central Intelligence", 2016, Movie::MovieType::MovieType_Film),
        Movie("Moana", 2016, Movie::MovieType::MovieType_Film), // Röst
        Movie("Jumanji: Welcome to the Jungle", 2017, Movie::MovieType::MovieType_Film),
        Movie("Rampage", 2018, Movie::MovieType::MovieType_Film),
        // TV-serie
        Movie("Ballers", 2015, Movie::MovieType::MovieType_Tv), // Startår, en TV-serie        
        Movie("Star Trek: Voyager",2000,Movie::MovieType::MovieType_Tv),
    };
    // Ta reda på FINNS DET NÅN FILM SOM ÄR SKAPAD 2005
    // BAD SEMANTICS
    // bool exists = false;
    // for(Movie movie :greatMovies){
    //     if(movie.getYear() == 2005){
    //         exists = true;
    //         break;
    //     }
    // }
    // if(exists == true){
    //     std::cout << "Ja det finns nån film som är skapad 2005" << std::endl;
    // }
    bool exists = std::any_of(std::begin(greatMovies), std::end(greatMovies), [](Movie const &movie){
        return movie.getYear() == 2005;
    });

    // STL = undvika loopar och istället låta koden "säga" vad den gör

    // int count = 0;
    // for(Movie movie :greatMovies){
    //     if(movie.getYear() == 2005){
    //         count++;
    //     }
    // }
    int count = std::count_if(std::begin(greatMovies),std::end(greatMovies),[](Movie const &movie){
        return movie.getYear() == 2005;
    });


    int count = std::count_if(greatMovies.begin(),greatMovies.end(),[](Movie const &movie){
        return movie.getYear() == 2005;
    });





    std::cout << "Antal skapade 2005" << count << std::endl;



    std::sort(std::begin(greatMovies), std::end(greatMovies),[] (Movie const &movie1,Movie const &movie2){
        return movie1.getYear() < movie2.getYear();
    } );



    for(Movie movie :greatMovies){ // går från början till slut
        std::cout << movie.getName() << std::endl;
    }

    std::for_each(std::begin(greatMovies), std::end(greatMovies),[](Movie const &movie){
        std::cout << movie.getName() << std::endl;
    });


    // std::for_each(std::end(greatMovies)-1, std::begin(greatMovies),[](Movie const &movie){
    //     std::cout << movie.getName() << std::endl;
    // });









    // // Finns det nån movie skapad 2000
    //  bool found = std::any_of(std::begin(greatMovies),std::end(greatMovies),[](Movie const &movie){
    //     return movie.getYear()  == 2000;
    // });

    // int count2 = std::count_if(std::begin(greatMovies),std::end(greatMovies),[](Movie const &movie){
    //     return movie.getYear()  == 2000;
    // });


    // int count = 0;
    // for(int i = 0; i < greatMovies.size();i++){
    //     if(greatMovies.at(i).getYear() == 2000){
    //         count++;
    //         break;
    //     }
    // }
    // if(count > 0){
    //     std::cout << "Ja den finnsa" << std::endl;
    // }

    
//     MyArray<int,12> allMonths;
//     allMonths.add(1);
//     allMonths.add(2);
    
//     for(int i =0; i < allMonths.size();i++){
//         std::cout << allMonths.getAt(i) << std::endl;
//     }

//     int i=12;
//     int j = 13;



//     int biggest = findBiggest<int>(12,99,11);
//     float bfloat = findBiggest<float>(12.99f,99.0f,110.0f);
//     std::string latest = findBiggest<std::string>("Stefan", "Anna","Östen");

//     //int biggest2 = findBiggest(12,99,11);


//    std::vector<int> nummer;
//    std::vector<std::string> namn;
//    std::vector<Player> player;


//     std::cout << "Hej" << std::endl;
}
    // int s = test(23,18); 
    // // push 23 (4 bytes)
    // // push 18 (4 bytes)
    // // jmp in i funktionen()
    // // ta pull 4 st bytes -> s

    // std::vector<int> arr = {
    //     12,12,45543,234,3,342
    // };
    // int smallest = findSmallest(arr);


    // std::vector<float> arr2 = {
    //     12.3f,12.342f,45543.342f,234.1f,3.0f,342.1223f
    // };
    // auto smallest2 = findSmallest(arr2);


    // // static
    // //std::vctor<int> INTE på embedded
    // // aldrig malloc/free på embedded - 
    // // STACKALLOKERADE DATASTRUKTURER
    // Player foppa;
    // foppa.Age = 52;
    // foppa.Name = "Peter";

    // MyArray<Player,1> team; 
    // team.add(foppa);

    // Player mats;
    // mats.Age = 53;
    // mats.Name = "Mats";
    // team.add(mats);

    // for(int i = 0; i < team.size(); i++){
    //     Player p = team.getAt(i);
    //     std::cout << p.Name << std::endl;
    // }

    // //team.removeAt(0);



    // // MyArray<int,10> array; //10
    // // MyArray<int,20> arrayPlayers; //20
    // // MyArray<float,10> array2; //


    // int tal1 = 12;
    // int tal2 = 13;
    // swap<int>(tal1,tal2);
    // std::cout << "Tal1:" <<  tal1 << " Tal2:" <<tal2 << std::endl;

    // float tal1f = 12.11f;
    // float tal2f = 13.11f;
    // swap<float>(tal1f,tal2f);
    // std::cout << "Tal1:" <<  tal1f << " Tal2:" <<tal2f << std::endl;



    // // int r,
    // // int s;
    // // test(r,s);
    // //skapa en SWAP-metod skicka a och b och när man kommer tillbaka är värdena flyttade 
    // // int v1 =12;
    // // int v2 = 13;
    // // swap<int>(v1,v2);
    // // std::cout << v1 << v2 << std::endl; // 13, 12
    // // float v1 =12;
    // // float v2 = 13;
    // // swap<float>(v1,v2);
    // // std::cout << v1 << v2 << std::endl; // 13, 12
    


    // // MyClass<int> 
    // // MyClass<float> 
    // int i = 11;
    // int j = 12;
    // int k = 13;

    // int b = findBiggest<int>(i,j,k);
    // //int b = findBiggest(i,j,k);
    // std::cout << b << std::endl;


    // std::string namn1 = "Anna";
    // std::string namn2 = "Bertil";    
    // std::string namn3 = "Carl";

    // std::string bigg = findBiggest<std::string>(namn1,namn2,namn3);
    // std::cout << bigg << std::endl;


    // float i2 = 11.44f;
    // float j2 = 12.11f;
    // float k2 = 13.44f;

    // float b2 = findBiggest<float>(i2,j2,k2);
    // std::cout << b2 << std::endl;



//}









// om T skulle betyda "int" så int findBiggest(int i, int j, int k)
// om T skulle betyda "float" så float findBiggest(float i, float j, float k)
// template<typename T>
// T findBiggest(T i, T j, T k){
//     if(i > j && i > k){
//         return i;
//     }
//     if(j > i && j > k){
//         return j;
//     }
//     return k; //fhdsklfsdh
// }



// double findBiggest(double i, double j, double k){
//     if(i > j && i > k){
//         return i;
//     }
//     if(j > i && j > k){
//         return j;
//     }
//     return k;
// }


// float findBiggest(float i, float j, float k){
//     if(i > j && i > k){
//         return i;
//     }
//     if(j > i && j > k){
//         return j;
//     }
//     return k; //
// }

// std::string findBiggest(std::string i, std::string j, std::string k){
//     if(i > j && i > k){
//         return i;
//     }
//     if(j > i && j > k){
//         return j;
//     }
//     return k; //
// }


// template <typename T>
// void swap(T &i, T &j) {
//     T temp = i;
//     i = j;
//     j  = temp;  
// }






// // std::vector<>
// // STL - standard template library
// //template<class T,int N>
// template<typename T,int N>
// class MyArray{
// public: 
//     MyArray(){
//         antal = 0;
//     }
//     void add(T one){
//         // om antalet > max 
//         // return "ERROR - finns inte plats för mer"
//         // 
//         things[antal] = one;
//         antal++;
//     }

//     // void removeAt(int index){
//     //     // foppa    kalle   stefan   lisa   anna   
//     //     //  0        1          2       3    4         antal = 5
//     //     // foppa    stefan     lisa    anna            antal = 4
//     //  }




//     int size(){
//         return antal;
//     }
//     T getAt(int index){
//         return things[index];
//     }


// private:
//     int antal;
//     T things[N]; // KAN INTE VÄXA/KRYMPA .- statisk i storlek  , INTE static
// };


// //EXERCISE 2:
// //Skriv en funktion som hittar MINSTA värdet i en array !
// template<typename T>
// T findSmallest(std::vector<T> arrayen){
//     T smallest = arrayen[0];
//     for(int i = 0; i < arrayen.size();i++ ){
//         if(arrayen[i] < smallest ){ // STEFAN SKA PRATA
//             smallest = arrayen[i];
//         }
//     }
//     return smallest;
//     //loopa och ta frtam minsta
//     // returnera
//     // TEMPLATED
// }


// int findBiggest(int i, int j, int k){
//     if(i > j && i > k){
//         return i;
//     }
//     if(j > i && j > k){
//         return j;
//     }
//     return k;
// }

// float findBiggest(float i, float j, float k){
//     if(i > j && i > k){
//         return i;
//     }
//     if(j > i && j > k){
//         return j;
//     }
//     return k;
// }


// std::string findBiggest(std::string i, std::string j, std::string k){
//     if(i > j && i > k){
//         return i;
//     }
//     if(j > i && j > k){
//         return j;
//     }
//     return k;
// }



// template <typename T>
// T findBiggest(T i, T j, T k){
//     if(i > j && i > k){
//         return i;
//     }
//     if(j > i && j > k){
//         return j;
//     }
//     return k;
// }


// template <typename T>
// void swap(T &i, T &j) {
//     T temp = i;
//     i = j;
//     j  = temp;  
// }


// template<typename T,int N>
// class MyArray{
// public: 
//     MyArray(){
//         antal = 0;
//     }
//     void add(T one){
//         // om antalet > max 
//         // return "ERROR - finns inte plats för mer"
//         // 
//         things[antal] = one;
//         antal++;
//     }

//     // void removeAt(int index){
//     //     // foppa    kalle   stefan   lisa   anna   
//     //     //  0        1          2       3    4         antal = 5
//     //     // foppa    stefan     lisa    anna            antal = 4
//     //  }




//     int size(){
//         return antal;
//     }
//     T getAt(int index){
//         return things[index];
//     }


// private:
//     int antal;
//     T things[N]; // KAN INTE VÄXA/KRYMPA .- statisk i storlek  , INTE static
// };

