#include <iostream>
#include <string>
using namespace std;

/* 请在这里填写答案 */
class BigInteger{
    public:
        BigInteger(){n = "";}
        friend ostream & operator<<(ostream & os,const BigInteger & a);
        friend istream & operator>>(istream & is,BigInteger & a);
        BigInteger operator*(const BigInteger & num);
        string n;
};

void add_on(int * r, int p, int n){
    //以下标p为起始位置，将n累加到数组r
    int jin = n, t;
    while(jin != 0){
        t = r[p] + jin;
        r[p++] = t % 10;
        jin = t / 10;
    } 
}

ostream & operator<<(ostream & os,const BigInteger & a){
    os << a.n;
    return os;
}

istream & operator>>(istream & is,BigInteger & a){
    is >> a.n;
    return is;
}

BigInteger BigInteger::operator*(const BigInteger & num){
    BigInteger res;
    string a = this -> n, b = num.n, t;
    int i, j, p, tmp, htmp, lena = a.length(), lenb = b.length(), jin, hjin;
    int r[10000] = {0};
    if(a == "0" || b == "0"){
        res.n = "0";
        return res;
    }
    for(j = lenb - 1; j >= 0; j--){
        p = -(j - lenb + 1);
        for(i = lena - 1, jin = 0, hjin = 0; i >= 0; i--){
            tmp = (b[j] - '0') * (a[i] - '0') + jin;
            add_on(r, p, tmp % 10);
            p++;
            jin = tmp / 10;
        }
        add_on(r, p, jin);
        p++;
    }
    for(i = p - 1, t = ""; i >= 0; i--){
        char c = '0' + r[i];
        t += c;
    }
    bool flag = false;
    for(i = 0; t[i]; i++){
        if(t[i] != '0'){
            flag = true;
        }
        if(flag == true){
            res.n += t[i];
        }
    }
    return res;
}
/******************/

int main() 
{
    BigInteger a, b, c;
    cin >> a >> b;
    c = a * b;
    cout << a << "*" << b << "=" << c << endl;
    return 0;
}
