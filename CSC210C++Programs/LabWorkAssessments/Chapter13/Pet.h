using namespace std;

class Pet {
  private:
    string breed;
    string name;
    string color;
	int    numpets;
    
  public:
    Pet();
    Pet(string,string,string, int);
    void set(string, string, string, int);
    void print();
    Pet operator+ (int);
};
