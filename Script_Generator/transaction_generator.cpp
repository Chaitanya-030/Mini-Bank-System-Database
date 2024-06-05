#include <bits/stdc++.h>
using namespace std;

int genaccperday(const int vec[])
{
    // Seed with a real random value, if available
    std::random_device rd;

    // Initialize a random number generator
    std::mt19937 gen(rd());

    // Create a uniform distribution for indices 0 to vec.size() - 1
    std::uniform_int_distribution<> dis(0, 6);

    // Generate and return a random index
    return dis(gen);
}

int genaccno(const int vec[])
{
    // Seed with a real random value, if available
    std::random_device rd;

    // Initialize a random number generator
    std::mt19937 gen(rd());

    // Create a uniform distribution for indices 0 to vec.size() - 1
    std::uniform_int_distribution<> dis(0, 192);

    // Generate and return a random index
    return dis(gen);
}

int gendesc(const string vec[])
{
    // Seed with a real random value, if available
    std::random_device rd;

    // Initialize a random number generator
    std::mt19937 gen(rd());

    // Create a uniform distribution for indices 0 to vec.size() - 1
    std::uniform_int_distribution<> dis(0, 3);

    // Generate and return a random index
    return dis(gen);
}

int gencrdr(const string vec[])
{
    // Seed with a real random value, if available
    std::random_device rd;

    // Initialize a random number generator
    std::mt19937 gen(rd());

    // Create a uniform distribution for indices 0 to vec.size() - 1
    std::uniform_int_distribution<> dis(0, 1);

    // Generate and return a random index
    return dis(gen);
}

int genamt(const int vec[])
{
    // Seed with a real random value, if available
    std::random_device rd;

    // Initialize a random number generator
    std::mt19937 gen(rd());

    // Create a uniform distribution for indices 0 to vec.size() - 1
    std::uniform_int_distribution<> dis(0, 7);

    // Generate and return a random index
    return dis(gen);
}

int genbal(int a, int b)
{
    // Use a random device to seed the random number generator
    std::random_device rd;
    std::mt19937 gen(rd());

    // Define the range [a, b]
    std::uniform_int_distribution<> dis(a, b);

    // Generate the random number
    return dis(gen);
}

int genchqno(const string vec[])
{
    // Seed with a real random value, if available
    std::random_device rd;

    // Initialize a random number generator
    std::mt19937 gen(rd());

    // Create a uniform distribution for indices 0 to vec.size() - 1
    std::uniform_int_distribution<> dis(0, 6);

    // Generate and return a random index
    return dis(gen);
}

// int ind1 = generateRandomIndex(dy);

int main()
{

    int arr[193];
    int j = 0;
    for (int i = 1; i <= 200; i++)
    {
        if (i >= 101 && i <= 150)
            continue;
        if (i == 3 || i == 47 || i == 56 || i == 89 || i == 163 || i == 130 || i == 191)
            continue;
        else
        {
            arr[j] = i;
            j++;
        }
    }

    int genaccnumber[7] = {5, 7, 2, 9, 16, 4, 12};

    string str[4] = {"rent", "utilities", "medical", "groceries"};
    string crdr[2] = {"Cr", "Dr"};
    int amt[8] = {1000, 9000, 10500, 5000, 12000, 5600, 13000, 6000};

    // Cash, CHQ-ISSUE, CHQ-ISSUE-RET, CHQ-DEPOSIT-RET, UPI, NEFT, RETGS

    string chq[7] = {"Cash", "CHQ_ISSUE", "CHQ-ISSUE-RET", "CHQ-DEPOSIT-RET", "UPI", "NEFT", "RETGS"};

    int tcnt = 0;
    int chequenumber = 1;
    for (int i = 1; i <= 31; i++)
    {
        int ind = genaccperday(genaccnumber);
        int lim = genaccnumber[ind]; // no. of accs we need on one day (random)
        for (j = 0; j < lim; j++)
        {
            string s = "";
            tcnt++;
            if (tcnt < 10)
                s += "00";
            if (tcnt >= 10 && tcnt <= 99)
                s += "0";

            int ind_accno = genaccno(arr);
            int accno = arr[ind_accno];

            string t = "";
            if (accno < 10)
                t += "00";
            if (accno >= 10 && accno <= 99)
                t += "0";

            string z = "";
            if (i < 10)
                z += "0";

            int ind_desc = gendesc(str);
            string desc = str[ind_desc];

            int ind_crdr = gencrdr(crdr);
            string credeb = crdr[ind_crdr];

            int ind_amt = genamt(amt);
            int amount = amt[ind_amt];

            int bal = genbal(25000, 100000);

            int ind_chq = genchqno(chq);
            string cheque = chq[ind_chq];

            string r = to_string(chequenumber);
            int sz = r.size();
            string ans = "";
            for (int i = 0; i < 10 - sz; i++)
            {
                ans += "0";
            }
            ans += r;

            cout << "INSERT INTO transaction VALUES('T" << s << tcnt << "'" << ", " << "'ACC" << t << accno << "'" << ", " << "'2024-01-" << z << i << "', " << "'"
                 << desc << "', " << "'" << credeb << "', " << amount << ", " << bal << ", '" << cheque << "', " << ans << ");" << endl;
            ;

            chequenumber++;
        }
    }

    return 0;
}