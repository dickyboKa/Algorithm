// two number
int gcd(int a, int b) 
{
    while (b > 0) 
    {
        int temp = b;
        b = a % b; // % is remainder
        a = temp;
    }
    return a;
}

// array of number
int gcd(int[] input) 
{
    int result = input[0];
    for (int i = 1; i < input.length; i++) 
    {
         result = gcd(result, input[i]);
    }
    return result;
}

int lcm(int a, int b) 
{
    return a * (b / gcd(a, b));
}

int lcm(int[] input) 
{
     int result = input[0];
     for (int i = 1; i < input.length; i++) 
     {
        result = lcm(result, input[i]);
     }
     return result;
}
