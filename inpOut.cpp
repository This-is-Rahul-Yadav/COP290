// #include<iostream>
// #include<fstream>
//
// using namespace std;
//
// int main() {
//
//  ifstream myReadFile;
//  myReadFile.open("test.txt");
//  char output[100];
//  if (myReadFile.is_open())
//  {
//    int c=0;
//    while (!myReadFile.eof())
//    {
//       cout << c<<"hey";
//       cout << endl;
//       myReadFile >> output;
//       cout<<output <<" ";
//       c++;
//    }
//    myReadFile.close();
//    return 0;
// }
// }



// #include <fstream>
// #include <iterator>
// #include <vector>
//
// int main()
// {
//     char filename[] = "test.txt";
//     std::vector<CoordinatePair> v;
//     std::ifstream ifs(filename);
//     if (ifs) {
//         std::copy(std::istream_iterator<CoordinatePair>(ifs),
//                 std::istream_iterator<CoordinatePair>(),
//                 std::back_inserter(v));
//     }
//     else {
//         std::cerr << "Couldn't open " << filename << " for reading\n";
//     }
//     // Now you can work with the contents of v
// }


// #include <fstream>
// #include <string>
// #include <iostream>
//
// int main()
// {
//     std::ifstream file("test.txt");
//     std::string str;
//     while (std::getline(file, str))
//     {
//         cout << str ;
//         cout << endl;
//     }
//     return 0;
// }

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {

ifstream file("inputfile.txt");
string content;

while(file >> content) {
cout << content << ' ';
cout << "hey";
}
return 0;
}


// #include <iostream>
// #include <fstream>
// using namespace std;
//
// int main(int argc, char *argv[])
// {
//   ifstream in("test.txt");
//   cout<< in;
//   if(!in) {
//     cout << "Cannot open input file.\n";
//     return 1;
//   }
//
//   char str[255];
//
//   while(in) {
//     in.getline(str, 255);
//     if(in) cout << str << endl;
//   }
//
//   in.close();
//
//   return 0;
// }
