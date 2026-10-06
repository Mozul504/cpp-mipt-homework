void trim_after_first_space(char str[])
{
    for (int i = 0; str[i] != '\0'; i++)
    {
        if (str[i] == ' ')
        {
            str[i] = '\0';
            return;   // дальше идти не нужно
        }
    }
}
