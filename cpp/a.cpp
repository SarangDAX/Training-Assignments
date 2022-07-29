#include <bits/stdc++.h>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <getopt.h>
using namespace std;

class Data
{
    public:
    vector<std::string> vdata;

    Data(std::vector<std::string> v){
        vdata = v;
    }

    string removeSpaces(string s)
    {
        s.erase(remove(s.begin(), s.end(), ' '), s.end());
        return s;
    }

    void show(){
        for (auto i = vdata.crbegin(); i != vdata.crend(); ++i){
            cout << *i << "\n";
            }
    }

    vector<vector<std::string>> allData(string s2){
        vector<vector<std::string>> res;
        for(int i = 0; i < vdata.size(); i++)
        {

            vector<std::string> tmp;
            string fname = removeSpaces(vdata[i].substr(15, 15));
            string lname = removeSpaces(vdata[i].substr(0, 15));
            string mname = removeSpaces(vdata[i].substr(30, 15));
            string aka = removeSpaces(vdata[i].substr(45, 5));
            string houseNo = removeSpaces(vdata[i].substr(55, 5));
            string sadd = removeSpaces(vdata[i].substr(59, 20));
            string city = removeSpaces(vdata[i].substr(80, 15));
            string state = removeSpaces(vdata[i].substr(94, 15));
            string zip = removeSpaces(vdata[i].substr(109, 6));

            
            string address1 = houseNo + ' ' + sadd;
            string address2 = city + ' '+ state + ' ' + zip;
            string name = fname + ' ' + lname;

            // For NICK-NAME:
            // if(s2 == "nn"){
            //     name = aka + ' ' + lname;

            // For Uppercase:
            // if(s2 == "uppercase"){
            //     transform(name.begin(), name.end(), name.begin(), ::toupper);
            //     transform(address1.begin(), address1.end(), address1.begin(), ::toupper);
            //     transform(address2.begin(), address2.end(), address2.begin(), ::toupper);
            // }

            tmp.push_back(name);
            tmp.push_back(address1);
            tmp.push_back(address2);


            // for MATCH-CODE:
            // if(s2 == "matchcode"){
            //     code = sadd.substr(0,1) + fname.substr(0,1) + zip;
            //     tmp.insert(tmp.begin(), code);
            // }

            res.push_back(tmp);

        }
        return res;
    }

    void Envolope(string s1)
    {
        cout<<"---------------------------------"<<"\n"<<"Envolope Format :"<<"\n"<<"---------------------------------"<<endl;
        vector<vector<std::string>> edata = allData(s1);
        for(vector<std::string> tmpv: edata){
            for(string line : tmpv){
                cout<< line <<endl;
            }
        }
        cout<<"\n";
        
    }

    void FixedFormat(string s1)
    {
        cout<<"---------------------------------"<<"\n"<<"Fixed Format :"<<"\n"<<"---------------------------------"<<endl;
        vector<vector<std::string>> edata = allData(s1);
        for(vector<std::string> tmpv: edata){
            int cnt = 0;
            for(string line : tmpv){
                cout<< line;
                switch(cnt){
                case 0:     for(int i=0; i<=(30 -line.length()); i++){
                            cout<<" ";}
                            break;

                case 1:     for(int i=0; i<=(25 -line.length()); i++){
                            cout<<" ";}
                            break;

                case 2:     for(int i=0; i<=(36 -line.length()); i++){
                            cout<<" ";}
                            break;
                }
                cnt++;
            }
            cout<<"\n";
        }
        cout<<"\n";
        
    }

    void FixedFormatWithCSV(string s1)
    {
        cout<<"---------------------------------"<<"\n"<<"Fixed Format With CSV :"<<"\n"<<"---------------------------------"<<endl;
        vector<vector<std::string>> edata = allData(s1);
        for(vector<std::string> tmpv: edata){
            for(string line : tmpv){
                cout<< line+",";
            }
            cout<<"\n";
        }
        cout<<"\n";
        
    }
};

// bool Nickname = false;
// bool Matchcode = false;
// bool Uppercase = false;
// bool Titlecase = false;
// string input_file;
// string command;

// void processArgs(int argc, char** argv)
// {
//     const char* const short_opts = "i:o:nmut";

//     const option long_opts[] = {
//             {"input_file", required_argument, nullptr, 'i'},
//             {"command", required_argument, nullptr, 'o'},
//             {"nick_name", no_argument, nullptr, 'n'},
//             {"matchcode", no_argument, nullptr, 'm'},
//             {"uppercase", no_argument, nullptr, 'u'},
//             {"titlecase", no_argument, nullptr, 't'},
//             {nullptr, no_argument, nullptr, 0}
//     };

//     while (true)
//     {
//         const auto opt = getopt_long(argc, argv, short_opts, long_opts, nullptr);

//         if (-1 == opt)
//             break;

//         switch (opt)
//         {
//           case 'i':
//               input_file = optarg;
//               break;

//           case 'o':
//               command = optarg;
//               break;

//           case 'n':
//               Nickname = true;
//               break;

//           case 'm':
//               Matchcode = true;
//               break;

//           case 'u': 
//               Uppercase = true;
//               break;

//           case 't': 
//               Titlecase = true;
//               break;

//           default:
//               break;
//         }
//     }
// }


int main(int argc, char *argv[])
{
    std::vector<std::string> vec_data; // Creating Vector form
    ifstream infile(argv[1]);          // open the file
    string str;
    cout<<vec_data.size();
    while (std::getline(infile, str))
    {
        // Line contains string of length > 0 then save it in vector
        if (str.size() > 0)
            vec_data.push_back(str);
    }
    cout<<vec_data.size();

    Data d(vec_data);
    if(argc>=3){
        string command = argv[2];
        if(command == "envelope")
            d.Envolope("reg");
        else if(command == "fixed_length")
            d.FixedFormat("reg");
        else if(command == "csv")
             d.FixedFormatWithCSV("reg");
    }
    else
        d.show();

    // if(command == "envelope"){
    //     if(Nickname)
    //         d.Envolope("nn");
    //     else if(Matchcode)
    //         d.Envolope("mc");
    //     else if(Uppercase)
    //         d.Envolope("uc");
    //     else if(Titlecase)
    //         d.Envolope("tc");
    // }

    // if(command == "FixedFormat"){
    //     if(Nickname)
    //         d.FixedFormat("nn");
    //     else if(Matchcode)
    //         d.FixedFormat("mc");
    //     else if(Uppercase)
    //         d.FixedFormat("uc");
    //     else if(Titlecase)
    //         d.FixedFormat("tc");
    // }

    // if(command == "csv"){
    //     if(Nickname)
    //         d.FixedFormatWithCSV("nn");
    //     else if(Matchcode)
    //         d.FixedFormatWithCSV("mc");
    //     else if(Uppercase)
    //         d.FixedFormatWithCSV("uc");
    //     else if(Titlecase)
    //         d.FixedFormatWithCSV("tc");
    // }
    return 0;
}