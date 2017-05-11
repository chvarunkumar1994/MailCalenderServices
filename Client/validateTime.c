int validateTime(char *time, int t)
{
  int i,j=0;
  char text[3];
  for(i = 0; i <= 1; i++,j++)
      text[i] = time[j];
  text[i] = '\0';
  hours[t] = atoi(text);
  j++;
  for(i = 0; i <= 1; i++,j++)
      text[i] = time[j];
  text[i] = '\0';
  mins[t] = atoi(text);
  
  if(mins[t] >= 00 && mins[t] <= 59 && hours[t] >= 00 && hours[t] <= 23)
    {
      return 1;
    }
  else
    {
      return 0;
    }

}