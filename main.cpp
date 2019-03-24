#include <iostream>
#include "observer.h"

int main() {

  // Create Subject 
  WeatherData *wd = new WeatherData; 

  // Create Current Conditions Display 
  CurrentConditions *cd = new CurrentConditions; 

  // Create Statisitcs Display 
  StatisticsDisplay *sd = new StatisticsDisplay; 

  // Register observers 
  wd->registerObserver(cd); 
  wd->registerObserver(sd); 

  // Update weather data 
  wd->setMeasurements(10, 5, 20); 

  // Display updates 
  cd->display(); 
  sd->display(); 

  // Unregister Satistics Display 
  wd->unregisterObserver(sd); 

  // Update weather data 
  wd->setMeasurements(1, 2, 3);  

  // Display updates 
  std::cout << "\n \n \n"; 
  cd->display();
  sd->display(); 

}
