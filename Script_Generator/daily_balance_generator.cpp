/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <bits/stdc++.h>
using namespace std;

int generateRandomIndex(const int vec[]) {
    // Seed with a real random value, if available
    std::random_device rd;
    
    // Initialize a random number generator
    std::mt19937 gen(rd());
    
    // Create a uniform distribution for indices 0 to vec.size() - 1
    std::uniform_int_distribution<> dis(0, 7);
    
    // Generate and return a random index
    return dis(gen);
}

int dx[8] = {200, -200, 500, -500, 950, 800, 850, 700};
int dy[8] = {10000, 7000, 5500, 5000, 2500, 5600, 7500,6000};

int main()
{
    map<int, vector<pair<int, int>>> v;
    for(int i=1;i<=200;i++) {
        for(int j=1;j<=30;j++) {
             int ind1 = generateRandomIndex(dy);
            if(i >= 101 && i <= 150)
            {
                 v[i].push_back({dy[ind1], dy[ind1]});
                 continue;
            }
            
           

            int ind2=generateRandomIndex(dx);

            
            if(j == 1) {
                v[i].push_back({dy[ind1], dy[ind1] + dx[ind2]});
            }
            else {
                v[i].push_back({v[i].back().second, v[i].back().second + dx[ind2]});
            }
        }
    }
    
    int i = 1;
    cout<<v.size()<<endl;
    for(auto it : v) {
        
        vector<pair<int,int>> &vp=it.second;
                    
            string s="";
            if(i<=9)
            s+="00";
            if(i<=99 && i>=10)
            s+='0';
        for(int j=1;j<=vp.size();++j)
        {
            
            
            
            

            string s1="";
            if(j<=9)
            s1+='0';
            cout<<"INSERT INTO dailybalance VALUES('ACC"<<s<<i<<"',"<<"'2024-04-"<<s1<<j<<"',"<<vp[j-1].first<<","<<vp[j-1].second<<");"<<endl;
        }
        i++;
        
    }

    return 0;
}

