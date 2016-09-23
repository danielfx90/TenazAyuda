#ifndef Input_h
#define Input_h

class Input {

  long coolDownInterrups;
  long countedInterrups;

protected:
  virtual void doUpdate() = 0;

public:
  Input(long coolDownInterrups);
	void update();
};

#endif
