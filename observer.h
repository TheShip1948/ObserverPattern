#include <vector>

// Observers Interface  
class Observer {
  public: 
    virtual void update(int humidity, int temp, int pressure) = 0; 
};

// Subject Interface 
class Subject {

  public: 
    void registerObserver(Observer *in);
    void unregisterObserver(Observer *in); 
    void notifyObservers(); 
};
// Subject: WeatherData 
class WeatherData : public Subject {
  private: 
    std::vector<Observer*> observers; 

    int humidity; 
    int temp; 
    int pressure; 

  public: 
    void registerObserver(Observer* in) {observers.push_back(in); } 
    void unregisterObserver(Observer* in) {

      std::vector<Observer*>::iterator observersItr; 
      
      int index = 0; 
      for(observersItr = observers.begin() ; observersItr != observers.end(); ++observersItr) {
       if( (*observersItr) == in) { break; }
                  
        index ++;  
      } 
      observers.erase(observers.begin()+index);      
    }

    void notifyObservers() {
      
      std::vector<Observer*>::iterator observersItr; 
      for(observersItr = observers.begin(); observersItr != observers.end(); ++observersItr) {
        (*observersItr)->update(humidity, temp, pressure); 
      }
    }

    void measurementsChanged() {
      notifyObservers(); 
    }

    void setMeasurements(int humidity, int temp, int pressure) {
      this->humidity = humidity; 
      this->temp = temp; 
      this->pressure = pressure; 
      measurementsChanged();
    }

};


// Display Interface 
class DisplayIfc {
  public: 
    virtual void display() = 0; 
};
// Current conditions 
class CurrentConditions : public Observer, public DisplayIfc {
  private: 
    int humidity; 
    int temp; 
    int pressure; 

  public: 
    void update(int humidity, int temp, int pressure) {
      this->humidity = humidity; 
      this->temp = temp; 
      this->pressure = pressure; 
    }

    void display() {
      std::cout << "Current Conditions: " << std::endl 
        << "Humidity = " << humidity << std::endl 
        << "temp = " << temp << std::endl 
        << "pressure = " << pressure << std::endl;  
    }
};


// Statistics Display 
class StatisticsDisplay : public Observer, public DisplayIfc {
  private: 
    int humidity; 
    int temp; 
    int pressure; 

  public: 
    void update(int humidity, int temp, int pressure) {
      this->humidity = humidity; 
      this->temp = temp; 
      this->pressure = pressure; 
    }

    void display() {
      std::cout << "Statisitics Display: " << std::endl 
        << "Humidity = " << humidity << std::endl 
        << "temp = " << temp << std::endl 
        << "pressure = " << pressure << std::endl;  
    }
};


