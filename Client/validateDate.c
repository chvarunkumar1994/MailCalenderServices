int daysInMonth(int month,int year)
{
  int days[]={31,0,31,30,31,30,31,31,30,31,30,31};

  days[1]=((year%4==0 && year%100 !=0) || year%400 ==0)?29:28;
  return days[month-1];

}

int validateDate(char *date,int t)
{
  int i,j=0;
  char text[5] ;
  for(i = 0; i <= 1; i++,j++)
    text[i] = date[j];
  text[i] = '\0';
  j++;
  month[t] = atoi(text);
  for(i = 0; i <= 1; i++,j++)
    text[i] = date[j];
  text[i] = '\0';
  day[t] = atoi(text);
  j++;
  for(i = 0; i <=3 ; i++,j++)
    text[i] = date[j];
  text[i] = '\0';
  year[t] = atoi(text);
  if(day[t] >= 1 && day[t] <= daysInMonth(month[t],year[t]) && month[t] >= 1 && month[t]<= 12)
    return 1;
  return 0;
}