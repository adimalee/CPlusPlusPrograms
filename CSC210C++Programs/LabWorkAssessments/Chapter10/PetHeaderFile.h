using namespace std;

class Pet {
  private:
    string breed;
    string name;
    string color;
    
  public:
    Pet();
    Pet(string,string,string);
    void set(string, string, string);
    void print();
};
