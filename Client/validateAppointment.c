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