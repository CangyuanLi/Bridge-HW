#include<iostream>
#include<cmath>
using namespace std;

void analyzeDividors(int num, int& outCountDivs, int& outSumDivs);
bool isPerfect(int num);

int main()
{
    int M;

    cout<<"Please enter a positive integer M (≥ 2): ";
    cin>>M;
    
    cout<<"List of perfect numbers from 2 to M:"<<endl;
    for(int i=2; i<=M; i++)
    {
        bool isPerfectNum = isPerfect(i);
        if(isPerfectNum>0)
            cout<<i<<" ";
    }
    cout<<endl;

    cout<<"All pairs of amicable numbers that are between 2 and M:"<<endl;
    for (int i = 2; i <= M; i++) 
    {
        int countDivs1, sumDivs1;
        int countDivs2, sumDivs2;

        analyzeDividors(i, countDivs1, sumDivs1);
        analyzeDividors(sumDivs1, countDivs2, sumDivs2);

        if ((i == sumDivs2) && (i < sumDivs1)) 
        {
            cout << '(' << i << ", " << sumDivs1 << ")\n";
        }
    }

    return 0;
}

void analyzeDividors(int num, int& outCountDivs, int& outSumDivs)
{
    int count = 0, sum = 0;
    for(int i=1; i<sqrt(num); i++)
    {
        if(num%i == 0)
        {
            count++;
            sum+=i;
            // cout<<i<<" ";
        }
    }

    for(int i=sqrt(num); i>0; i--)
    {
        if(num%i == 0)
        {
            count++;
            sum+=(num/i);
            // cout<<num/i<<" ";
        }
    }

    // finding count and sum of proper divisors
    outCountDivs = count-1;
    outSumDivs = sum-num;

}

bool isPerfect(int num)
{
    int outCountDivs, outSumDivs;

    analyzeDividors(num, outCountDivs, outSumDivs);
    // cout<<outSumDivs<<" "<<num<<endl;

    return outSumDivs == num;
}