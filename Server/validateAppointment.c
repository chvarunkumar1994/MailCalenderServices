
void validateDate(char *date,int t)
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
}

void validateTime(char *time, int t)
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
  // //printf("mins: %d, hours: %d\n",mins[t],hours[t]);
  /*if(mins[t] >= 00 && mins[t] <= 59 && hours[t] >= 00 && hours[t] <= 23)
    {
      return 1;
    }
  else
    {
      return 0;
    }
*/
}

int validateAppointment(int i, int j)
{
  
  if((mins[i] < mins[j] && hours[i] == hours[j] && day[i] == day[j] && month[i] == month[j] && year[i] == year[j]) ||
     (hours[i] < hours[j] && day[i] == day[j] && month[i] == month[j] && year[i] == year[j]) ||
     (day[i] < day[j] && month[i] == month[j] && year[i] == year[j]) ||
     (month [i] < month[j] &&  year[i] == year[j]) || 
     (year[i] < year[j]))
    {
      return 1;
    }
  else
    {
      return 0;
    }
}