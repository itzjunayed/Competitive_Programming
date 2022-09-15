/**
 * @author Junayed
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include<bits/stdc++.h>
#define fio ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0)
#define ll long long
#define endl "/n"
const int N=1e6;
using namespace std;

// Prime checker
bool checkPrime(int n)
{
    if (n <= 1)
        return false;

    for (int i = 2; i * i <= n; i++)
        if (n % i == 0)
            return false;
    return true;
}
// GCD
int gcd(int a, int b)
{
    if(b==0)
        return a;
    return gcd(b, a % b);
}
// LCM
int lcm(int a, int b)
{
    return (a * b) / gcd(a, b);
}
// bigmod
int bigmod(int base, int power, int mod)
{
    if(power==0)
        return 1;
    else if(power%2==1)
    {
        int a=base%mod;
        int b=(bigmod(base, power-1,mod))%mod;
        return (a*b)%mod;
    }
    else
    {
        int a=(bigmod(base,power/2,mod))%mod;
        return (a*a)%mod;
    }
}
//Sieve
bool isPrime[N+1];
vector<int> primes;
void sieve()
{
    for(int i=1; i<=N; i++)
    {
        isPrime[i] = true;
    }
    isPrime[1] = false;
    for(int i = 4; i<=N; i+=2)
    {
        isPrime[i] = false;
    }
    for(int i=3; i*i <= N; i+=2)
    {
        if(isPrime[i])
        {
            for(int j=i*i; j<=N; j+=2*i)
            {
                isPrime[j] = false;
            }
        }
    }
    for(int i=2; i<=N; i++)
    {
        if(isPrime[i]) 
            primes.push_back(i);
    }
}
//NOD (Number of Divisor)
int NOD[N+5];
void generateNOD()
{
    for(int i=1; i<=N; i++)
    {
        for(int j=i; j<=N; j+=i)
        {
            NOD[j]++;
        }
    }
}
//SOD (Sum of Divisor)
int SOD[N+5];
void generateSOD()
{
    for(int i=1; i<=N; i++)
    {
        for(int j=i; j<=N; j+=i)
        {
            SOD[j]+=i;
        }
    }
}

// Base Convertion Decilmal
int val(char c)
{
    if (c >= '0' && c <= '9')
        return (int)c - '0';
    else 
        return (int)c - 'A' + 10;
}

// Function to convert a number from given base 'b'
// to decimal
int toDeci(string str, int base)
{
    int len = str.size(); 
    int power = 1;
    int num = 0;
    int i;
    for (i = len - 1; i >= 0; i--)
    {
        // A digit in input number must be less than number's base
        if (val(str[i]) >= base)
        {
            printf("Invalid Number");
            return -1;
        }
        num += val(str[i]) * power;
        power = power * base;
    }

    return num;
}
//BinarySearch
bool binarySearch(vector<int> v, int value)
{
    int low=0;
    int high=v.size()-1;
    while(low<=high)
    {
        int mid = (low+high)/2;
        if(v[mid]==value)
            return true;
        else if(v[mid]<value)
            low=mid+1;
        else
            high = mid-1;
    }
    return false;
}
bool div(string str, int num)
{
    int r=0;
    for(int i=0; i<str.length(); i++)
    {
        int digit = str[i]-'0';
        r = (r*10)+digit;
        r %= num;
    }
    if(r==0)
        return true;
    else
        return false;
}
//leapyear
bool leapYear(string year)
{
    if(div(year,400))
        return true;
    else if(div(year,100))
        return false;
    else if(div(year,4))
        return true;
    else
        return false;
}

int main()
{
    
}