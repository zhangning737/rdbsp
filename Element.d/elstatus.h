#ifndef _ELSTATUS_H_
#define _ELSTATUS_H_

class elstatus {
 public:
  double mass;
  double vol0;
  double vol;
  double stress[6];
  double strain[6];
  double energy[3];
  double fm;
  elstatus() {
    mass = 0.0;
    vol0 = 0.0;
    vol = 0.0;
    int i;
    for (i = 0; i < 3; ++i) {
      stress[i] = 0.0;
      strain[i] = 0.0;
      energy[i] = 0.0;
    }
    for (i = 3; i < 6; ++i) {
      stress[i] = 0.0;
      strain[i] = 0.0;
    }
  }
};

#endif
