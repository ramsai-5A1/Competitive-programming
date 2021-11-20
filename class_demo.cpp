#include <bits/stdc++.h>
using namespace std;

class box
{
    public:
    string name, dob;
    double percentage;

    box(string name, double percentage, string dob)
    {
        this -> name = name;
        this -> percentage = percentage;
        this -> dob = dob;
    }
};


class cmp
{
    public:
    bool operator()(box a, box b)
    {
        if(a.percentage != b.percentage)
            return a.percentage > b.percentage;
        int n1 = a.name.length();
        int n2 = b.name.length();
        return n1 > n2;
    }
};


int main()
{
    int n;
    cin >> n;
    vector<box> vec;

    for(int i = 0; i < n; i++)
    {
        string name, dob;
        double percentage;
        cin >> name >> dob >> percentage;

        box obj(name, percentage, dob);
        vec.push_back(obj);
    }

    cout << "Before sorting \n";
    for(int i = 0; i < n; i++)
        cout << vec[i].name << " " << vec[i].percentage << " " << vec[i].dob << endl;
    cout << endl << endl;

    sort(vec.begin(), vec.end(), cmp());
    for(int i = 0; i < n; i++)
        cout << vec[i].name << " " << vec[i].percentage << " " << vec[i].dob << endl;
    return 0;
}
