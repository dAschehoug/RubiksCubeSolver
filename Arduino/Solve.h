#ifndef Solve.h
#define Solve_h
#include "Arduino.h"
Position p;

class Solution {
public:
  void whiteCross() {
    //Fix first cubie
    if ((front[1] != front[4]) || (up[7] != up[4])) {
      if (up[7] == front[4] && front[1] == up[4]) {
        p.FCW();
        p.RCW();
        p.UCW();
      } else if (front[5] == front[4] && right[3] == up[4]) {
        p.FCCW();
      } else if (right[3] == front[4] && front[5] == up[4]) {
        p.RCW();
        p.UCW();
      } else if (front[7] == front[4] && down[1] == up[4]) {
        p.FCW();
        p.FCW();
      } else if (down[1] == front[4] && front[7] == up[4]) {
        p.FCCW();
        p.RCW();
        p.UCW();
      } else if (front[3] == front[4] && left[5] == up[4]) {
        p.FCW();
      } else if (left[5] == front[4] && front[3] == up[4]) {
        p.LCCW();
        p.UCCW();
      }
      // FØRSTE CUBIE DEL AV UP-RIGHT/UP-LEFT
      else if (right[1] == front[4] && up[5] == up[4]) {
        p.UCW();
      } else if (up[5] == front[4] && right[1] == up[4]) {
        p.RCCW();
        p.FCCW();
      } else if ((up[3] == front[4]) && (left[1] == up[4])) {
        p.LCW();
        p.FCW();

      } else if (left[1] == front[4] && up[3] == up[4]) {
        p.UCCW();
      }
      //FØRSTE CUBIE DEL AV DOWN-RIGHT/DOWN-LEFT
      else if (down[5] == front[4] && right[7] == up[4]) {
        p.RCW();
        p.FCCW();
      } else if (right[7] == front[4] && down[5] == up[4]) {
        p.DCCW();
        p.FCW();
        p.FCW();
      } else if (left[7] == front[4] && down[3] == up[4]) {
        p.LCCW();
        p.LCCW();
        p.UCCW();
      } else if (down[3] == front[4] && left[7] == up[4]) {
        p.LCCW();
        p.FCW();
      }
      // FØRSTE CUBIE ER DEL AV HARDRIGHT
      else if (back[1] == front[4] && up[1] == up[4]) {
        p.UCW();
        p.UCW();
      } else if (up[1] == front[4] && back[1] == up[4]) {
        p.BCCW();
        p.RCCW();
        p.UCW();
      } else if (back[3] == front[4] && right[5] == up[4]) {
        p.RCW();
        p.RCW();
        p.FCCW();
      } else if (right[5] == front[4] && back[3] == up[4]) {
        p.RCCW();
        p.UCW();
      } else if (back[7] == front[4] && down[7] == up[4]) {
        p.BCW();
        p.BCW();
        p.UCW();
        p.UCW();
      } else if (down[7] == front[4] && back[7] == up[4]) {
        p.DCCW();
        p.RCW();
        p.FCCW();
      } else if (back[5] == front[4] && left[3] == up[4]) {
        p.LCCW();
        p.LCCW();
        p.FCW();
      } else if (left[3] == front[4] && back[5] == up[4]) {
        p.LCW();
        p.UCCW();
      } else {
        Serial.println("There was a problem, first cubie ");
      }
    }
    //Fix second cubie
    if ((front[5] != front[4]) || (right[3] != right[4])) {
      if (front[5] == right[4] && right[3] == front[4]) {
        p.RCCW();
        p.FCW();
        p.DCCW();
        p.FCCW();
      } else if (front[7] == front[4] && down[1] == right[4]) {
        p.UCW();
        p.FCCW();
        p.UCCW();
      } else if (down[1] == front[4] && front[7] == right[4]) {
        p.DCW();
        p.RCW();
      } else if (front[3] == front[4] && left[5] == right[4]) {
        p.UCW();
        p.FCW();
        p.FCW();
        p.UCCW();
      } else if (left[5] == front[4] && front[3] == right[4]) {
        p.LCCW();
        p.UCCW();
        p.FCW();
        p.UCW();
      }
      // SECOND CUBIE IN TOP-LEFT/TOP-RIGHT
      else if (up[5] == front[4] && right[1] == right[4]) {
        p.RCCW();
      } else if (right[1] == front[4] && up[5] == right[4]) {
        p.FCCW();
        p.UCW();
        p.FCW();
      } else if (up[3] == front[4] && left[1] == right[4]) {
        p.LCCW();
        p.BCW();
        p.BCW();
        p.RCW();
        p.RCW();
      } else if (left[1] == front[4] && up[3] == right[4]) {
        p.UCCW();
        p.FCW();
        p.UCW();
      }
      //SECOND CUBIE IN DOWN-RIGHT/DOWN-LEFT
      else if (down[5] == front[4] && right[7] == right[4]) {
        p.RCW();
      } else if (right[7] == front[4] && down[5] == right[4]) {
        p.FCW();
        p.DCCW();
        p.FCCW();
      } else if (down[3] == front[4] && left[7] == right[4]) {
        p.DCW();
        p.DCW();
        p.RCW();
      } else if (left[7] == front[4] && down[3] == right[4]) {
        p.FCW();
        p.DCW();
        p.FCCW();
      }
      //SECOND CUBIE IS HARDRIGHT
      else if (up[1] == front[4] && back[1] == right[4]) {
        p.UCW();
        p.RCCW();
        p.UCCW();
      } else if (back[1] == front[4] && up[1] == right[4]) {
        p.BCCW();
        p.RCW();
        p.RCW();
      } else if (back[3] == front[4] && right[5] == right[4]) {
        p.RCW();
        p.RCW();
      } else if (right[5] == front[4] && back[3] == right[4]) {
        p.BCW();
        p.UCW();
        p.RCCW();
        p.UCCW();
      } else if (back[7] == front[4] && down[7] == right[4]) {
        p.BCW();
        p.RCW();
        p.RCW();
      } else if (down[7] == front[4] && back[7] == right[4]) {
        p.DCCW();
        p.RCW();
      } else if (back[5] == front[4] && left[3] == right[4]) {
        p.BCW();
        p.BCW();
        p.RCW();
        p.RCW();
      } else if (left[3] == front[4] && back[5] == right[4]) {
        p.FCW();
        p.LCCW();
        p.DCW();
        p.FCCW();
      } else {
        Serial.print("Problem with second cubie");
      }
    }
    //Fix third cubie
    if ((front[7] != front[4]) || (down[1] != down[4])) {
      if (down[1] == front[4] && front[7] == down[4]) {
        p.DCW();
        p.FCCW();
        p.RCW();
        p.FCW();
      } else if (left[5] == front[4] && front[3] == down[4]) {
        p.LCW();
        p.DCW();
      } else if (front[3] == front[4] && left[5] == down[4]) {
        p.LCW();
        p.FCW();
        p.LCCW();
        p.FCCW();
      }
      //THIRD CUBIE IS TOP-RIGHT/TOP-LEFT
      else if (right[1] == front[4] && up[5] == down[4]) {
        p.RCW();
        p.RCW();
        p.DCCW();
        p.RCW();
        p.RCW();
      } else if (up[5] == front[4] && right[1] == down[4]) {
        p.FCCW();
        p.RCCW();
        p.FCW();
      } else if (left[1] == front[4] && up[3] == down[4]) {
        p.LCW();
        p.LCW();
        p.DCW();
      } else if (up[3] == front[4] && left[1] == down[4]) {
        p.FCW();
        p.LCW();
        p.FCCW();
      }
      //THIRD CUBIE IS DOWN-RIGHT/DOWN-LEFT
      else if (down[5] == front[4] && right[7] == down[4]) {
        p.FCCW();
        p.RCW();
        p.FCW();
      } else if (right[7] == front[4] && down[5] == down[4]) {
        p.DCCW();
      } else if (down[3] == front[4] && left[7] == down[4]) {
        p.FCW();
        p.LCCW();
        p.FCCW();
      } else if (left[7] == front[4] && down[3] == down[4]) {
        p.DCW();
      }
      //THIRD CUBIE IS HARDRIGHT
      else if (back[1] == front[4] && up[1] == down[4]) {
        p.BCW();
        p.BCW();
        p.DCW();
        p.DCW();
      } else if (up[1] == front[4] && back[1] == down[4]) {
        p.BCCW();
        p.RCW();
        p.DCCW();
        p.RCCW();
      } else if (right[5] == front[4] && back[3] == down[4]) {
        p.RCW();
        p.DCCW();
        p.RCCW();
      } else if (back[3] == front[4] && right[5] == down[4]) {
        p.BCCW();
        p.DCW();
        p.DCW();
      } else if (down[7] == front[4] && back[7] == down[4]) {
        p.DCCW();
        p.FCCW();
        p.RCW();
        p.FCW();
      } else if (back[7] == front[4] && down[7] == down[4]) {
        p.DCW();
        p.DCW();
      } else if (left[3] == front[4] && back[5] == down[4]) {
        p.LCCW();
        p.DCW();
      } else if (back[5] == front[4] && left[3] == down[4]) {
        p.BCW();
        p.DCW();
        p.DCW();
      } else {
        Serial.println("Problem with third cubie");
      }
    }
    //Fix forth cubie
    if ((front[3] != front[4]) || (left[5] != left[4])) {
      if (left[5] == front[4] && front[3] == left[4]) {
        p.LCW();
        p.FCCW();
        p.DCW();
        p.FCW();
      }
      //FORTH CUBIE IN TOP-RIGHT/TOP-LEFT
      else if (up[5] == front[4] && right[1] == left[4]) {
        p.FCW();
        p.FCW();
        p.RCCW();
        p.FCW();
        p.FCW();
      } else if (right[1] == front[4] && up[5] == left[4]) {
        p.FCW();
        p.UCW();
        p.FCCW();
      } else if (up[3] == front[4] && left[1] == left[4]) {
        p.LCW();
      } else if (left[1] == front[4] && up[3] == left[4]) {
        p.FCW();
        p.UCCW();
        p.FCCW();
      }
      //FORTH CUBIE IN DOWN-RIGHT/DOWN-LEFT
      else if (down[5] == front[4] && right[7] == left[4]) {
        p.FCW();
        p.FCW();
        p.RCW();
        p.FCW();
        p.FCW();
      } else if (right[7] == front[4] && down[5] == left[4]) {
        p.FCCW();
        p.DCCW();
        p.FCW();
      } else if (down[3] == front[4] && left[7] == left[4]) {
        p.LCCW();
      } else if (left[7] == front[4] && down[3] == left[4]) {
        p.FCCW();
        p.DCW();
        p.FCW();
      }
      // FORTH CUBIE IS BACK
      else if (up[1] == front[4] && back[1] == left[4]) {
        p.UCCW();
        p.LCW();
        p.UCW();
      } else if (back[1] == front[4] && up[1] == left[4]) {
        p.BCW();
        p.LCW();
        p.LCW();
      } else if (right[5] == front[4] && back[3] == left[4]) {
        p.BCW();
        p.UCCW();
        p.LCW();
        p.UCW();
      } else if (back[3] == front[4] && right[5] == left[4]) {
        p.BCW();
        p.BCW();
        p.LCW();
        p.LCW();
      } else if (down[7] == front[4] && back[7] == left[4]) {
        p.DCW();
        p.LCCW();
        p.DCCW();
      } else if (back[7] == front[4] && down[7] == left[4]) {
        p.BCCW();
        p.LCW();
        p.LCW();
      } else if (back[5] == front[4] && left[3] == left[4]) {
        p.LCW();
        p.LCW();
      } else if (left[3] == front[4] && back[5] == left[4]) {
        p.LCW();
        p.FCW();
        p.UCCW();
        p.FCCW();
      }
    }
  }

  void F2L() {
    //GET FIRST CUBIE TOP POSITION
    if (front[2] != front[4] || up[8] != up[4] || right[0] != right[4] || up[5] != up[4] || right[1] != right[4]) {
      if (front[2] == right[4] && up[8] == front[4] && right[0] == up[4]) {
        p.RCW();
        p.BCW();
        p.RCCW();
        p.LCCW();
        p.BCW();
        p.LCW();
        p.BCW();
      } else if (front[2] == front[4] && up[8] == up[4] && right[0] == right[4]) {
        p.RCW();
        p.BCW();
        p.RCCW();
        p.BCCW();

      } else if (front[2] == up[4] && up[8] == right[4] && right[0] == front[4]) {
        p.RCW();
        p.BCW();
        p.RCCW();
        p.UCW();
        p.BCCW();
        p.UCCW();
        p.BCW();
      } else if (front[0] == right[4] && up[6] == up[4] && left[2] == front[4]) {
        p.LCCW();
        p.BCCW();
        p.LCW();
      } else if (front[0] == up[4] && left[2] == right[4] && up[6] == front[4]) {
        p.LCCW();
        p.BCCW();
        p.LCW();
        p.UCCW();
        p.BCW();
        p.UCW();
        p.BCW();
        p.BCW();
      } else if (front[0] == front[4] && up[6] == right[4] && left[2] == up[4]) {
        p.UCW();
        p.BCW();
        p.UCCW();
        p.BCW();
        p.BCW();
      } else if (front[8] == front[4] && right[6] == up[4] && down[2] == right[4]) {
        p.DCW();
        p.BCW();
        p.DCCW();
      } else if (down[2] == front[4] && front[8] == up[4] && right[6] == right[4]) {
        p.DCW();
        p.BCW();
        p.DCCW();
        p.RCW();
        p.BCCW();
        p.RCCW();
        p.BCW();
        p.BCW();
      } else if (right[6] == front[4] && front[8] == right[4] && down[2] == up[4]) {
        p.DCW();
        p.BCW();
        p.DCCW();
        p.UCCW();
        p.BCW();
        p.UCW();
        p.BCW();
        p.BCW();
      } else if (down[0] == front[4] && front[6] == right[4] && left[8] == up[4]) {
        p.DCCW();
        p.BCW();
        p.BCW();
        p.DCW();
      } else if (front[6] == front[4] && down[0] == up[4] && left[8] == right[4]) {
        p.LCW();
        p.BCW();
        p.BCW();
        p.LCCW();
      } else if (left[8] == front[4] && down[0] == right[4] && front[6] == up[4]) {
        p.LCW();
        p.DCW();
        p.LCCW();
        p.DCW();
        p.BCW();
        p.BCW();
        p.DCCW();
      } else if (up[2] == front[4] && right[2] == right[4] && back[0] == up[4]) {
        //do nothing
      } else if (right[2] == front[4] && back[0] == right[4] && up[2] == up[4]) {
        p.RCW();
        p.BCCW();
        p.RCCW();
        p.BCW();
        p.BCW();
      } else if (back[0] == front[4] && up[2] == right[4] && right[2] == up[4]) {
        p.UCCW();
        p.BCW();
        p.UCW();
        p.BCW();
        p.BCW();
      } else if (right[8] == front[4] && back[6] == up[4] && down[8] == right[4]) {
        p.BCW();
      } else if (down[8] == front[4] && right[8] == up[4] && back[6] == right[4]) {
        p.DCW();
        p.BCCW();
        p.DCCW();
        p.BCCW();
      } else if (back[6] == front[4] && right[8] == right[4] && down[8] == up[4]) {
        p.RCCW();
        p.BCW();
        p.RCW();
        p.BCCW();
      } else if (down[6] == front[4] && left[6] == right[4] && back[8] == up[4]) {
        p.BCW();
        p.BCW();
      } else if (left[6] == front[4] && down[6] == up[4] && back[8] == right[4]) {
        p.LCW();
        p.BCCW();
        p.LCCW();
      } else if (back[8] == front[4] && left[6] == up[4] && down[6] == right[4]) {
        p.DCCW();
        p.BCW();
        p.DCW();
      } else if (left[0] == front[4] && up[0] == right[4] && back[2] == up[4]) {
        p.BCCW();
      } else if (up[0] == front[4] && left[0] == up[4] && back[2] == right[4]) {
        p.UCW();
        p.BCCW();
        p.UCCW();
        p.BCW();
      } else if (back[2] == front[4] && left[0] == right[4] && up[0] == up[4]) {
        p.LCCW();
        p.BCW();
        p.BCW();
        p.LCW();
      }  //FIRST CUBIE PLACED CORRECTLY FOR F2L, SIDE PIECE IS TOP-RIGHT/TOP-LEFT
      if (up[5] == up[4] && right[1] == right[4]) {
        p.BCW();
        p.RCW();
        p.BCW();
        p.DCW();
        p.BCW();
        p.DCCW();
        p.BCCW();
        p.BCCW();
        p.RCCW();
      } else if (up[5] == right[4] && right[1] == up[4]) {
        p.BCCW();
        p.UCCW();
        p.BCCW();
        p.DCW();
        p.BCCW();
        p.BCCW();
        p.DCCW();
        p.UCW();
        p.RCW();
        p.BCW();
        p.BCW();
        p.RCCW();
      } else if (left[1] == up[4] && up[3] == right[4]) {
        p.LCCW();
        p.BCCW();
        p.LCW();
        p.RCCW();
        p.BCW();
        p.RCW();
        p.BCW();
        p.BCW();
        p.UCCW();
        p.BCW();
        p.UCW();
      } else if (left[1] == right[4] && up[3] == up[4]) {
        p.LCCW();
        p.BCCW();
        p.RCW();
        p.BCW();
        p.BCW();
        p.RCCW();
        p.LCW();
        p.BCW();
        p.BCW();
        p.RCW();
        p.BCCW();
        p.RCCW();
      }
      //FIRST CUIBIE, SIDE PIECE IS DOWN-RIGHT/DOWN-LEFT
      else if (right[7] == right[4] && down[5] == up[4]) {
        p.BCW();
        p.UCW();
        p.BCCW();
        p.UCCW();
        p.DCW();
        p.BCW();
        p.UCCW();
        p.BCW();
        p.DCCW();
        p.UCW();
      } else if (right[7] == up[4] && down[5] == right[4]) {
        p.DCW();
        p.UCW();
        p.BCW();
        p.UCCW();
        p.DCCW();
        p.BCW();
        p.RCW();
        p.BCCW();
        p.RCCW();
      } else if (left[7] == up[4] && down[3] == right[4]) {
        p.LCW();
        p.BCCW();
        p.LCCW();
        p.RCCW();
        p.BCW();
        p.BCW();
        p.RCW();
        p.UCCW();
        p.BCW();
        p.BCW();
        p.UCW();
      } else if (left[7] == right[4] && down[3] == up[4]) {
        p.LCW();
        p.BCCW();
        p.LCCW();
        p.RCW();
        p.BCW();
        p.BCW();
        p.RCCW();
        p.BCCW();
        p.BCCW();
        p.RCW();
        p.BCCW();
        p.RCCW();
      }
      //FIRST CUBIE, SIDE PIECE BACK
      else if (up[1] == right[4] && back[1] == up[4]) {
        p.RCCW();
        p.BCW();
        p.RCW();
        p.UCW();
        p.BCW();
        p.BCW();
        p.UCCW();
        p.BCW();
        p.RCW();
        p.BCCW();
        p.RCCW();
      } else if (up[1] == up[4] && back[1] == right[4]) {
        p.RCCW();
        p.BCW();
        p.RCW();
        p.UCCW();
        p.BCCW();
        p.UCW();
      } else if (left[3] == right[4] && back[5] == up[4]) {
        p.UCW();
        p.BCW();
        p.BCW();
        p.UCCW();
        p.BCW();
        p.RCW();
        p.BCCW();
        p.RCCW();
      } else if (left[3] == up[4] && back[5] == right[4]) {
        p.UCCW();
        p.BCCW();
        p.UCW();
      } else if (back[7] == up[4] && down[7] == right[4]) {
        p.UCW();
        p.BCW();
        p.UCCW();
        p.BCW();
        p.RCW();
        p.BCCW();
        p.RCCW();
      } else if (back[7] == right[4] && down[7] == up[4]) {
        p.UCW();
        p.BCCW();
        p.UCCW();
        p.UCCW();
        p.BCCW();
        p.UCW();
      } else if (right[5] == up[4] && back[3] == right[4]) {
        p.UCW();
        p.BCW();
        p.BCW();
        p.UCCW();
        p.UCCW();
        p.BCCW();
        p.UCW();
      } else if (right[5] == right[4] && back[3] == up[4]) {
        p.BCW();
        p.RCW();
        p.BCCW();
        p.RCCW();
      } else {
        Serial.print("noe galt med F2L, første cubie");
      }
    }
    //SECOND CUBIE TOP POSITION
    if (front[8] != front[4] || right[6] != right[4] || down[2] != down[4] || right[7] != right[4] || down[5] != down[4]) {
      if (front[8] == front[4] && right[6] == right[4] && down[2] == down[4]) {
        p.DCW();
        p.BCW();
        p.DCCW();
        p.BCCW();
      } else if (down[2] == front[4] && front[8] == right[4] && right[6] == down[4]) {
        p.DCW();
        p.BCW();
        p.DCCW();
        p.BCCW();
        p.DCW();
        p.BCCW();
        p.DCCW();
        p.BCW();
        p.BCW();
      } else if (right[6] == front[4] && down[2] == right[4] && front[8] == down[4]) {
        p.RCCW();
        p.BCCW();
        p.RCW();
        p.BCW();
      } else if (front[6] == front[4] && down[0] == right[4] && left[8] == down[4]) {
        p.LCW();
        p.BCW();
        p.LCCW();
      } else if (left[8] == front[4] && front[6] == right[4] && down[0] == down[4]) {
        p.DCCW();
        p.BCCW();
        p.DCW();
        p.LCCW();
        p.BCW();
        p.LCW();
      } else if (down[0] == front[4] && left[8] == right[4] && front[6] == down[4]) {
        p.DCCW();
        p.BCCW();
        p.DCW();
        p.BCW();
        p.BCW();
      } else if (front[0] == front[4] && left[2] == right[4] && up[6] == down[4]) {
        p.UCW();
        p.BCW();
        p.BCW();
        p.UCCW();
      } else if (up[6] == front[4] && front[0] == right[4] && left[2] == down[4]) {
        p.LCCW();
        p.BCW();
        p.LCW();
        p.UCW();
        p.BCCW();
        p.UCCW();
      } else if (left[2] == front[4] && up[6] == right[4] && front[0] == down[4]) {
        p.LCCW();
        p.BCW();
        p.BCW();
        p.LCW();
      } else if (up[2] == front[4] && back[0] == right[4] && right[2] == down[4]) {
        p.BCCW();
      } else if (right[2] == front[4] && up[2] == right[4] && back[0] == down[4]) {
        p.BCW();
        p.UCW();
        p.BCCW();
        p.UCCW();
      } else if (back[0] == front[4] && right[2] == right[4] && up[2] == down[4]) {
        p.BCW();
        p.LCCW();
        p.BCW();
        p.LCW();
      } else if (right[8] == front[4] && back[6] == right[4] && down[8] == down[4]) {
        //do nothing
      } else if (down[8] == front[4] && right[8] == right[4] && back[6] == down[4]) {
        p.DCW();
        p.BCCW();
        p.DCCW();
        p.BCW();
        p.BCW();
      } else if (back[6] == front[4] && down[8] == right[4] && right[8] == down[4]) {
        p.RCCW();
        p.BCW();
        p.RCW();
        p.BCW();
        p.BCW();
      } else if (down[6] == front[4] && back[8] == right[4] && left[6] == down[4]) {
        p.BCW();
      } else if (left[6] == front[4] && down[6] == right[4] && back[8] == down[4]) {
        p.LCW();
        p.BCW();
        p.BCW();
        p.LCCW();
      } else if (back[8] == front[4] && left[6] == right[4] && down[6] == down[4]) {
        p.DCCW();
        p.BCW();
        p.DCW();
        p.BCCW();
      } else if (left[0] == front[4] && back[2] == right[4] && up[0] == down[4]) {
        p.BCW();
        p.BCW();
      } else if (up[0] == front[4] && left[0] == right[4] && back[2] == down[4]) {
        p.UCW();
        p.BCCW();
        p.UCCW();
      } else if (back[2] == front[4] && up[0] == right[4] && left[0] == down[4]) {
        p.LCCW();
        p.BCW();
        p.LCW();
      }
      //SECOND CUBIE, SECOND F2L, SIDE PIECE DOWN-RIGHT/DOWN-LEFT
      if (right[7] == right[4] && down[5] == down[4]) {
        p.BCW();
        p.DCW();
        p.UCW();
        p.BCW();
        p.UCCW();
        p.BCCW();
        p.DCCW();
      } else if (down[5] == right[4] && right[7] == down[4]) {
        p.BCCW();
        p.RCCW();
        p.BCCW();
        p.RCW();
        p.LCW();
        p.BCW();
        p.BCW();
        p.LCCW();
        p.DCW();
        p.BCW();
        p.BCW();
        p.DCCW();
      } else if (down[3] == right[4] && left[7] == down[4]) {
        p.LCW();
        p.BCW();
        p.LCCW();
        p.UCW();
        p.BCW();
        p.UCCW();
        p.DCW();
        p.BCCW();
        p.DCCW();
      } else if (left[7] == right[4] && down[3] == down[4]) {
        p.BCW();
        p.DCCW();
        p.UCW();
        p.BCW();
        p.UCCW();
        p.DCW();
        p.DCW();
        p.BCCW();
        p.DCCW();
      } else if (left[1] == right[4] && up[3] == down[4]) {
        p.UCW();
        p.RCW();
        p.BCW();
        p.BCW();
        p.RCCW();
        p.UCCW();
        p.BCW();
        p.DCW();
        p.BCCW();
        p.DCCW();
      } else if (up[3] == right[4] && left[1] == down[4]) {
        p.LCCW();
        p.BCW();
        p.LCW();
        p.UCW();
        p.BCW();
        p.UCCW();
        p.DCW();
        p.BCCW();
        p.DCCW();
      }
      //SIDE PIECE IN BACK
      else if (back[1] == right[4] && up[1] == down[4]) {
        p.BCW();
        p.UCW();
        p.DCW();
        p.BCW();
        p.BCW();
        p.UCCW();
        p.BCCW();
        p.DCCW();
      } else if (up[1] == right[4] && back[1] == down[4]) {
        p.RCCW();
        p.BCCW();
        p.RCW();
      } else if (back[3] == right[4] && right[5] == down[4]) {
        p.DCCW();
        p.BCW();
        p.DCW();
        p.BCW();
        p.UCW();
        p.DCW();
        p.BCW();
        p.BCW();
        p.UCCW();
        p.BCCW();
        p.DCCW();
      } else if (right[5] == right[4] && back[3] == down[4]) {
        p.DCCW();
        p.BCW();
        p.DCW();
        p.RCCW();
        p.BCCW();
        p.RCW();
      } else if (back[7] == right[4] && down[7] == down[4]) {
        p.BCW();
        p.DCW();
        p.BCCW();
        p.DCCW();
      } else if (down[7] == right[4] && back[7] == down[4]) {
        p.BCW();
        p.UCW();
        p.BCW();
        p.BCW();
        p.UCCW();
        p.BCCW();
        p.RCCW();
        p.BCCW();
        p.RCW();
      } else if (left[3] == right[4] && back[5] == down[4]) {
        p.BCW();
        p.UCW();
        p.BCCW();
        p.UCCW();
        p.BCCW();
        p.RCCW();
        p.BCCW();
        p.RCW();
      } else if (back[5] == right[4] && left[3] == down[4]) {
        p.BCW();
        p.UCW();
        p.BCW();
        p.UCCW();
        p.DCW();
        p.BCCW();
        p.DCCW();
      } else {
        Serial.print("problem second cubie F2L");
      }
    }
    //GET THIRD CUBIE TOP POSITION
    if (front[6] != front[4] || left[8] != left[4] || down[0] != down[4] || left[7] != left[4] || down[3] != down[4]) {
      if (front[6] == front[4] && left[8] == left[4] && down[0] == down[4]) {
        p.LCW();
        p.BCW();
        p.LCCW();
        p.BCCW();
      } else if (left[8] == front[4] && down[0] == left[4] && front[6] == down[4]) {
        p.DCCW();
        p.BCCW();
        p.DCW();
        p.LCCW();
        p.BCW();
        p.LCW();
        p.BCCW();
      } else if (down[0] == front[4] && front[6] == left[4] && left[8] == down[4]) {
        p.DCCW();
        p.BCCW();
        p.DCW();
        p.BCW();
      } else if (front[0] == front[4] && up[6] == left[4] && left[2] == down[4]) {
        p.UCW();
        p.BCW();
        p.UCCW();
      } else if (up[6] == front[4] && left[2] == left[4] && front[0] == down[4]) {
        p.LCCW();
        p.BCCW();
        p.LCW();
        p.BCW();
        p.LCCW();
        p.BCW();
        p.LCW();
        p.BCCW();
      } else if (left[2] == front[4] && front[0] == left[4] && up[6] == down[4]) {
        p.LCCW();
        p.BCCW();
        p.LCW();
        p.BCW();
        p.BCW();
      } else if (up[2] == front[4] && right[2] == left[4] && back[0] == down[4]) {
        p.BCW();
        p.BCW();
      } else if (right[2] == front[4] && back[0] == left[4] && up[2] == down[4]) {
        p.BCW();
        p.UCW();
        p.BCW();
        p.BCW();
        p.UCCW();
      } else if (back[0] == front[4] && up[2] == left[4] && right[2] == down[4]) {
        p.BCW();
        p.LCCW();
        p.BCW();
        p.LCW();
        p.BCCW();
      } else if (right[8] == front[4] && down[8] == left[4] && back[6] == down[4]) {
        p.BCCW();
      } else if (down[8] == front[4] && back[6] == left[4] && right[8] == down[4]) {
        p.BCCW();
        p.LCW();
        p.BCCW();
        p.LCCW();
        p.BCW();
        p.BCW();
      } else if (back[6] == front[4] && right[8] == left[4] && down[8] == down[4]) {
        p.BCCW();
        p.DCCW();
        p.BCW();
        p.DCW();
        p.BCW();
        p.BCW();
      } else if (down[6] == front[4] && left[6] == left[4] && back[8] == down[4]) {
        //do nothing
      } else if (left[6] == front[4] && back[8] == left[4] && down[6] == down[4]) {
        p.LCW();
        p.BCCW();
        p.LCCW();
        p.BCW();
        p.BCW();
      } else if (back[8] == front[4] && down[6] == left[4] && left[6] == down[4]) {
        p.DCCW();
        p.BCW();
        p.DCW();
        p.BCW();
        p.BCW();
      } else if (left[0] == front[4] && up[0] == left[4] && back[2] == down[4]) {
        p.BCW();
      } else if (up[0] == front[4] && back[2] == left[4] && left[0] == down[4]) {
        p.UCW();
        p.BCW();
        p.BCW();
        p.UCCW();
      } else if (back[2] == front[4] && left[0] == left[4] && up[0] == down[4]) {
        p.LCCW();
        p.BCW();
        p.LCW();
        p.BCCW();
      } else {
        Serial.print("problem third cubie F2L, corner");
      }
      //THIRD CUBIE, SIDE PIECE IN MIDDLE
      if (up[3] == down[4] && left[1] == left[4]) {
        p.BCW();
        p.LCCW();
        p.BCW();
        p.LCW();
        p.UCW();
        p.BCW();
        p.UCCW();
        p.LCW();
        p.BCW();
        p.BCW();
        p.LCCW();
      } else if (up[3] == left[4] && left[1] == down[4]) {
        p.UCW();
        p.BCW();
        p.UCCW();
        p.BCW();
        p.UCW();
        p.BCW();
        p.UCCW();
        p.LCW();
        p.BCW();
        p.BCW();
        p.LCCW();
      } else if (left[7] == left[4] && down[3] == down[4]) {
        p.BCCW();
        p.DCCW();
        p.BCCW();
        p.DCW();
        p.BCW();
        p.LCCW();
        p.BCW();
        p.BCW();
        p.LCW();
        p.DCCW();
        p.BCW();
        p.BCW();
        p.DCW();
      } else if (left[7] == down[4] && down[3] == left[4]) {
        p.BCW();
        p.BCW();
        p.LCW();
        p.BCW();
        p.LCCW();
        p.BCCW();
        p.DCCW();
        p.BCW();
        p.DCW();
      } else if (up[1] == left[4] && back[1] == down[4]) {
        p.BCCW();
        p.LCW();
        p.BCW();
        p.LCCW();
        p.BCW();
        p.BCW();
        p.LCW();
        p.BCCW();
        p.LCCW();
      } else if (up[1] == down[4] && back[1] == left[4]) {
        p.LCCW();
        p.BCCW();
        p.LCW();
        p.DCCW();
        p.BCCW();
        p.DCW();
      } else if (right[5] == left[4] && back[3] == down[4]) {
        p.BCCW();
        p.LCW();
        p.BCW();
        p.BCW();
        p.LCCW();
        p.BCW();
        p.BCW();
        p.LCW();
        p.BCCW();
        p.LCCW();
      } else if (right[5] == down[4] && back[3] == left[4]) {
        p.DCCW();
        p.BCCW();
        p.DCW();
      } else if (down[7] == left[4] && back[7] == down[4]) {
        p.LCCW();
        p.BCW();
        p.LCW();
        p.BCCW();
        p.LCW();
        p.BCW();
        p.BCW();
        p.LCCW();
        p.BCW();
        p.BCW();
        p.LCW();
        p.BCCW();
        p.LCCW();
      } else if (back[7] == left[4] && down[7] == down[4]) {
        p.LCCW();
        p.BCW();
        p.LCW();
        p.DCCW();
        p.BCCW();
        p.DCW();
      } else if (left[3] == left[4] && back[5] == down[4]) {
        p.BCW();
        p.LCW();
        p.BCCW();
        p.LCCW();
      } else if (left[3] == down[4] && back[5] == left[4]) {
        p.BCCW();
        p.LCW();
        p.BCW();
        p.BCW();
        p.LCCW();
        p.BCW();
        p.DCCW();
        p.BCCW();
        p.DCW();
      } else {
        Serial.print("problem third cubie, F2L, sidepiece");
      }
    }
    //GET FORTH CUBIE TOP POSITION
    if (front[0] != front[4] || up[6] != up[4] != left[2] != left[4] || left[1] != left[4] || up[3] != up[4]) {
      if (front[0] == front[4] && up[6] == up[4] && left[2] == left[4]) {
        p.UCW();
        p.BCW();
        p.UCCW();
        p.BCW();
        p.BCW();
      } else if (up[6] == front[4] && left[2] == up[4] && front[0] == left[4]) {
        p.LCCW();
        p.BCCW();
        p.LCW();
        p.BCW();
        p.LCCW();
        p.BCW();
        p.BCW();
        p.LCW();
      } else if (left[2] == front[4] && front[0] == up[4] && up[6] == left[4]) {
        p.LCCW();
        p.BCCW();
        p.LCW();
      } else if (up[2] == front[4] && right[2] == up[4] && back[0] == left[4]) {
        //do nothing
      } else if (right[2] == front[4] && back[0] == up[4] && up[2] == left[4]) {
        p.BCW();
        p.UCW();
        p.BCCW();
        p.UCCW();
        p.BCW();
      } else if (back[0] == front[4] && up[2] == up[4] && right[2] == left[4]) {
        p.BCW();
        p.LCCW();
        p.BCW();
        p.BCW();
        p.LCW();
      } else if (right[8] == front[4] && down[8] == up[4] && back[6] == left[4]) {
        p.BCW();
      } else if (down[8] == front[4] && back[6] == up[4] && right[8] == left[4]) {
        p.BCCW();
        p.BCCW();
        p.UCW();
        p.BCCW();
        p.UCCW();
        p.BCW();
      } else if (back[6] == front[4] && right[8] == up[4] && down[8] == left[4]) {
        p.BCW();
        p.BCW();
        p.LCCW();
        p.BCW();
        p.BCW();
        p.LCW();
      } else if (down[6] == front[4] && left[6] == up[4] && back[8] == left[4]) {
        p.BCW();
        p.BCW();
      } else if (left[6] == front[4] && back[8] == up[4] && down[6] == left[4]) {
        p.BCCW();
        p.UCW();
        p.BCCW();
        p.UCCW();
        p.BCW();
      } else if (back[8] == front[4] && down[6] == up[4] && left[6] == left[4]) {
        p.BCCW();
        p.LCCW();
        p.BCW();
        p.BCW();
        p.LCW();
      } else if (left[0] == front[4] && up[0] == up[4] && back[2] == left[4]) {
        p.BCCW();
      } else if (up[0] == front[4] && back[2] == up[4] && left[0] == left[4]) {
        p.UCW();
        p.BCCW();
        p.UCCW();
        p.BCW();
      } else if (back[2] == front[4] && left[0] == up[4] && up[0] == left[4]) {
        p.LCCW();
        p.BCW();
        p.BCW();
        p.LCW();
      } else {
        Serial.print("problem forth cubie, F2L, corner");
      }
      //PLACING FORTH CUBIE WITH SIDE PIECE
      if (up[3] == up[4] && left[1] == left[4]) {
        p.LCCW();
        p.BCCW();
        p.LCW();
        p.BCW();
        p.BCW();
        p.LCCW();
        p.BCCW();
        p.LCW();
      } else if (left[1] == up[4] && up[3] == left[4]) {
        p.UCW();
        p.BCW();
        p.UCCW();
        p.BCW();
        p.LCCW();
        p.BCCW();
        p.LCW();
      } else if (up[1] == up[4] && back[1] == left[4]) {
        p.BCW();
        p.LCCW();
        p.BCW();
        p.LCW();
        p.BCW();
        p.BCW();
        p.UCW();
        p.BCW();
        p.UCCW();
      } else if (up[1] == left[4] && back[1] == up[4]) {
        p.BCW();
        p.BCW();
        p.LCCW();
        p.BCW();
        p.LCW();
        p.BCCW();
        p.LCCW();
        p.BCCW();
        p.LCW();
      } else if (right[5] == up[4] && back[3] == left[4]) {
        p.BCW();
        p.BCW();
        p.UCW();
        p.BCCW();
        p.UCCW();
      } else if (right[5] == left[4] && back[3] == up[4]) {
        p.UCW();
        p.BCW();
        p.BCW();
        p.UCCW();
        p.BCW();
        p.LCCW();
        p.BCCW();
        p.LCW();
      } else if (down[7] == up[4] && back[7] == left[4]) {
        p.UCW();
        p.BCW();
        p.UCCW();
        p.BCW();
        p.BCW();
        p.UCW();
        p.BCCW();
        p.UCCW();
      } else if (back[7] == up[4] && down[7] == left[4]) {
        p.UCW();
        p.BCCW();
        p.UCCW();
        p.BCW();
        p.LCCW();
        p.BCCW();
        p.LCW();
      } else if (left[3] == up[4] && back[5] == left[4]) {
        p.UCW();
        p.BCW();
        p.BCW();
        p.UCCW();
        p.BCW();
        p.BCW();
        p.UCW();
        p.BCCW();
        p.UCCW();
      } else if (left[3] == left[4] && back[5] == up[4]) {
        p.BCW();
        p.LCCW();
        p.BCCW();
        p.LCW();
      } else {
        Serial.print("Problem forth cubie, F2L, side piece");
      }
    }
  }

  void OLL() {
    p.XCCW();
    for (int j = 0; j < 4; j++) {
      if (up[0] != up[4] || up[1] != up[4] || up[2] != up[4] || up[3] != up[4] || up[5] != up[4] || up[6] != up[4] || up[7] != up[4] || up[8] != up[4]) {
        //case 1
        if (front[1] == up[4] && left[0] == up[4] && left[1] == up[4] && left[2] == up[4] && right[0] == up[4] && right[1] == up[4] && right[2] == up[4] && back[1] == up[4]) {
          p.RCW();
          p.UCW();
          p.UCW();
          p.RCW();
          p.RCW();
          p.FCW();
          p.RCW();
          p.FCCW();
          p.UCW();
          p.UCW();
          p.RCCW();
          p.FCW();
          p.RCW();
          p.FCCW();
        }
        //case 2
        else if (front[1] == up[4] && left[1] == up[4] && left[2] == up[4] && right[0] == up[4] && right[1] == up[4] && back[0] == up[4] && back[1] == up[4] && back[2] == up[4]) {
          p.rCW();
          p.UCW();
          p.rCCW();
          p.UCW();
          p.UCW();
          p.rCW();
          p.UCW();
          p.UCW();
          p.RCCW();
          p.UCW();
          p.UCW();
          p.RCW();
          p.UCCW();
          p.rCCW();
        }
        //case 3
        else if (front[1] == up[4] && front[2] == up[4] && left[1] == up[4] && right[1] == up[4] && right[2] == up[4] && back[1] == up[4] && back[2] == up[4] && up[6] == up[4]) {
          p.rCCW();
          p.RCW();
          p.RCW();
          p.UCW();
          p.RCCW();
          p.UCW();
          p.rCW();
          p.UCW();
          p.UCW();
          p.rCCW();
          p.UCW();
          p.MCCW();
        }
        //case 4
        else if (front[0] == up[4] && front[1] == up[4] && left[0] == up[4] && left[1] == up[4] && right[1] == up[4] && back[0] == up[4] && back[1] == up[4] && up[8] == up[4]) {
          p.MCW();
          p.UCCW();
          p.rCW();
          p.UCW();
          p.UCW();
          p.rCCW();
          p.UCCW();
          p.RCW();
          p.UCCW();
          p.RCCW();
          p.MCCW();
        }
        //case 5
        else if (front[1] == up[4] && front[2] == up[4] && left[2] == up[4] && right[1] == up[4] && right[2] == up[4] && up[0] == up[4] && up[1] == up[4] && up[3] == up[4]) {
          p.lCCW();
          p.UCW();
          p.UCW();
          p.LCW();
          p.UCW();
          p.LCCW();
          p.UCW();
          p.lCW();
        }
        //case 6
        else if (front[0] == up[4] && front[1] == up[4] && left[0] == up[4] && left[1] == up[4] && right[0] == up[4] && up[1] == up[4] && up[2] == up[4] && up[5] == up[4]) {
          p.rCW();
          p.UCW();
          p.UCW();
          p.RCCW();
          p.UCCW();
          p.RCW();
          p.UCCW();
          p.rCCW();
        }
        //case 7
        else if (front[1] == up[4] && front[2] == up[4] && right[1] == up[4] && right[2] == up[4] && back[2] == up[4] && up[1] == up[4] && up[3] == up[4] && up[6] == up[4]) {
          p.rCW();
          p.UCW();
          p.RCCW();
          p.UCW();
          p.RCW();
          p.UCW();
          p.UCW();
          p.rCCW();
        }
        //case 8
        else if (front[0] == up[4] && front[1] == up[4] && left[0] == up[4] && left[1] == up[4] && back[0] == up[4] && up[1] == up[4] && up[5] == up[4] && up[8] == up[4]) {
          p.lCCW();
          p.UCCW();
          p.LCW();
          p.UCCW();
          p.LCCW();
          p.UCW();
          p.UCW();
          p.lCW();
        }
        //case 9
        else if (front[0] == up[4] && front[1] == up[4] && left[0] == up[4] && right[1] == up[4] && back[0] == up[4] && up[1] == up[4] && up[3] == up[4] && up[8] == up[4]) {
          p.RCW();
          p.UCW();
          p.RCCW();
          p.UCCW();
          p.RCCW();
          p.FCW();
          p.RCW();
          p.RCW();
          p.UCW();
          p.RCCW();
          p.UCCW();
          p.FCCW();
        }
        //case 10
        else if (front[2] == up[4] && left[2] == up[4] && right[1] == up[4] && back[1] == up[4] && back[2] == up[4] && up[2] == up[4] && up[3] == up[4] && up[7] == up[4]) {
          p.RCW();
          p.UCW();
          p.RCCW();
          p.UCW();
          p.RCCW();
          p.FCW();
          p.RCW();
          p.FCCW();
          p.RCW();
          p.UCW();
          p.UCW();
          p.RCCW();
        }
        // case 11
        else if (front[1] == up[4] && front[2] == up[4] && left[2] == up[4] && right[1] == up[4] && back[2] == up[4] && up[1] == up[4] && up[2] == up[4] && up[3] == up[4]) {
          p.rCW();
          p.UCW();
          p.RCCW();
          p.UCW();
          p.RCCW();
          p.FCW();
          p.RCW();
          p.FCCW();
          p.RCW();
          p.UCW();
          p.UCW();
          p.rCCW();
        }
        // case 12
        else if (front[0] == up[4] && front[1] == up[4] && left[1] == up[4] && right[0] == up[4] && back[0] == up[4] && up[0] == up[4] && up[1] == up[4] && up[5] == up[4]) {
          p.MCCW();
          p.RCCW();
          p.UCCW();
          p.RCW();
          p.UCCW();
          p.RCCW();
          p.UCW();
          p.UCW();
          p.RCW();
          p.UCCW();
          p.RCW();
          p.rCCW();
        }
        // case 13
        else if (front[1] == up[4] && front[2] == up[4] && right[2] == up[4] && back[1] == up[4] && back[2] == up[4] && up[3] == up[4] && up[5] == up[4] && up[6] == up[4]) {
          p.FCW();
          p.UCW();
          p.RCW();
          p.UCCW();
          p.RCW();
          p.RCW();
          p.FCCW();
          p.RCW();
          p.UCW();
          p.RCW();
          p.UCCW();
          p.RCCW();
        }
        // case 14
        else if (front[0] == up[4] && front[1] == up[4] && left[0] == up[4] && back[0] == up[4] && back[1] == up[4] && up[3] == up[4] && up[5] == up[4] && up[8] == up[4]) {
          p.RCCW();
          p.FCW();
          p.RCW();
          p.UCW();
          p.RCCW();
          p.FCCW();
          p.RCW();
          p.FCW();
          p.UCCW();
          p.FCCW();
        }
        // case 15
        else if (front[1] == up[4] && front[2] == up[4] && left[2] == up[4] && right[2] == up[4] && back[1] == up[4] && up[1] == up[4] && up[3] == up[4] && up[5] == up[4]) {
          p.lCCW();
          p.UCCW();
          p.lCW();
          p.LCCW();
          p.UCCW();
          p.LCW();
          p.UCW();
          p.lCCW();
          p.UCW();
          p.lCW();
        }
        // case 16
        else if (front[0] == up[4] && front[1] == up[4] && left[0] == up[4] && right[0] == up[4] && back[1] == up[4] && up[2] == up[4] && up[3] == up[4] && up[5] == up[4]) {
          p.rCW();
          p.UCW();
          p.rCCW();
          p.RCW();
          p.UCW();
          p.RCCW();
          p.UCCW();
          p.rCW();
          p.UCCW();
          p.rCCW();
        }
        // case 17
        else if (front[0] == up[4] && front[1] == up[4] && left[1] == up[4] && right[1] == up[4] && right[2] == up[4] && back[1] == up[4] && up[0] == up[4] && up[8] == up[4]) {
          p.FCW();
          p.RCCW();
          p.FCCW();
          p.RCW();
          p.RCW();
          p.rCCW();
          p.UCW();
          p.RCW();
          p.UCCW();
          p.RCCW();
          p.UCCW();
          p.MCCW();
        }
        // case 18
        else if (front[0] == up[4] && front[1] == up[4] && front[2] == up[4] && left[1] == up[4] && right[1] == up[4] && back[1] == up[4] && up[0] == up[4] && up[2] == up[4]) {
          p.rCW();
          p.UCW();
          p.RCCW();
          p.UCW();
          p.RCW();
          p.UCW();
          p.UCW();
          p.rCW();
          p.rCW();
          p.UCCW();
          p.RCW();
          p.UCCW();
          p.RCCW();
          p.UCW();
          p.UCW();
          p.rCW();
        }
        //case 19
        else if (front[1] == up[4] && left[1] == up[4] && left[2] == up[4] && right[0] == up[4] && right[1] == up[4] && back[1] == up[4] && up[0] == up[4] && up[2] == up[4]) {
          p.rCCW();
          p.RCW();
          p.UCW();
          p.RCW();
          p.UCW();
          p.RCCW();
          p.UCCW();
          p.MCCW();
          p.RCCW();
          p.FCW();
          p.RCW();
          p.FCCW();
        }
        // case 20
        else if (front[1] == up[4] && left[1] == up[4] && right[1] == up[4] && back[1] == up[4] && up[0] == up[4] && up[2] == up[4] && up[6] == up[4] && up[8] == up[4]) {
          p.rCW();
          p.UCW();
          p.RCCW();
          p.UCCW();
          p.MCW();
          p.MCW();
          p.UCW();
          p.RCW();
          p.UCCW();
          p.RCCW();
          p.UCCW();
          p.MCCW();
        }
        // case 21
        else if (front[0] == up[4] && front[2] == up[4] && back[0] == up[4] && back[2] == up[4] && up[1] == up[4] && up[3] == up[4] && up[5] == up[4] && up[7] == up[4]) {
          p.RCW();
          p.UCW();
          p.UCW();
          p.RCCW();
          p.UCCW();
          p.RCW();
          p.UCW();
          p.RCCW();
          p.UCCW();
          p.RCW();
          p.UCCW();
          p.RCCW();
        }
        // case 22
        else if (front[2] == up[4] && left[0] == up[4] && left[2] == up[4] && back[0] == up[4] && up[1] == up[4] && up[3] == up[4] && up[5] == up[4] && up[7] == up[4]) {
          p.RCW();
          p.UCW();
          p.UCW();
          p.RCW();
          p.RCW();
          p.UCCW();
          p.RCW();
          p.RCW();
          p.UCCW();
          p.RCW();
          p.RCW();
          p.UCW();
          p.UCW();
          p.RCW();
        }
        // case 23
        else if (back[0] == up[4] && back[2] == up[4] && up[1] == up[4] && up[3] == up[4] && up[5] == up[4] && up[6] == up[4] && up[7] == up[4] && up[8] == up[4]) {
          p.RCW();
          p.RCW();
          p.DCCW();
          p.RCW();
          p.UCW();
          p.UCW();
          p.RCCW();
          p.DCW();
          p.RCW();
          p.UCW();
          p.UCW();
          p.RCW();
        }
        // case 24
        else if (front[0] == up[4] && back[2] == up[4] && up[1] == up[4] && up[2] == up[4] && up[3] == up[4] && up[5] == up[4] && up[7] == up[4] && up[8] == up[4]) {
          p.rCW();
          p.UCW();
          p.RCCW();
          p.UCCW();
          p.rCCW();
          p.FCW();
          p.RCW();
          p.FCCW();
        }
        // case 25
        else if (front[2] == up[4] && left[0] == up[4] && up[1] == up[4] && up[2] == up[4] && up[3] == up[4] && up[5] == up[4] && up[6] == up[4] && up[7] == up[4]) {
          p.FCCW();
          p.rCW();
          p.UCW();
          p.RCCW();
          p.UCCW();
          p.rCCW();
          p.FCW();
          p.RCW();
        }
        // case 26
        else if (front[0] == up[4] && left[0] == up[4] && right[0] == up[4] && up[1] == up[4] && up[2] == up[4] && up[3] == up[4] && up[5] == up[4] && up[7] == up[4]) {
          p.RCW();
          p.UCW();
          p.UCW();
          p.RCCW();
          p.UCCW();
          p.RCW();
          p.UCCW();
          p.RCCW();
        }
        // case 27
        else if (front[2] == up[4] && right[2] == up[4] && back[2] == up[4] && up[1] == up[4] && up[3] == up[4] && up[5] == up[4] && up[6] == up[4] && up[7] == up[4]) {
          p.RCW();
          p.UCW();
          p.RCCW();
          p.UCW();
          p.RCW();
          p.UCW();
          p.UCW();
          p.RCCW();
        }
        // case 28
        else if (front[1] == up[4] && right[1] == up[4] && up[0] == up[4] && up[1] == up[4] && up[2] == up[4] && up[3] == up[4] && up[6] == up[4] && up[8] == up[4]) {
          p.rCW();
          p.UCW();
          p.RCCW();
          p.UCCW();
          p.rCCW();
          p.RCW();
          p.UCW();
          p.RCW();
          p.UCCW();
          p.RCCW();
        }
        // case 29
        else if (front[0] == up[4] && front[1] == up[4] && right[1] == up[4] && back[2] == up[4] && up[1] == up[4] && up[2] == up[4] && up[3] == up[4] && up[8] == up[4]) {
          p.RCW();
          p.UCW();
          p.RCCW();
          p.UCCW();
          p.RCW();
          p.UCCW();
          p.RCCW();
          p.FCCW();
          p.UCCW();
          p.FCW();
          p.RCW();
          p.UCW();
          p.RCCW();
        }
        // case 30
        else if (front[1] == up[4] && left[0] == up[4] && right[1] == up[4] && right[2] == up[4] && up[1] == up[4] && up[3] == up[4] && up[6] == up[4] && up[8] == up[4]) {
          p.FCW();
          p.RCCW();
          p.FCW();
          p.RCW();
          p.RCW();
          p.UCCW();
          p.RCCW();
          p.UCCW();
          p.RCW();
          p.UCW();
          p.RCCW();
          p.FCW();
          p.FCW();
        }
        // case 31
        else if (front[0] == up[4] && front[1] == up[4] && left[1] == up[4] && back[2] == up[4] && up[1] == up[4] && up[2] == up[4] && up[5] == up[4] && up[8] == up[4]) {
          p.RCCW();
          p.UCCW();
          p.FCW();
          p.UCW();
          p.RCW();
          p.UCCW();
          p.RCCW();
          p.FCCW();
          p.RCW();
        }
        // case 32
        else if (front[1] == up[4] && front[2] == up[4] && right[1] == up[4] && back[0] == up[4] && up[0] == up[4] && up[1] == up[4] && up[3] == up[4] && up[6] == up[4]) {
          p.LCW();
          p.UCW();
          p.FCCW();
          p.UCCW();
          p.LCCW();
          p.UCW();
          p.LCW();
          p.FCW();
          p.LCCW();
        }
        // case 33
        else if (front[0] == up[4] && front[1] == up[4] && back[1] == up[4] && back[2] == up[4] && up[2] == up[4] && up[3] == up[4] && up[5] == up[4] && up[8] == up[4]) {
          p.RCW();
          p.UCW();
          p.RCCW();
          p.UCCW();
          p.RCCW();
          p.FCW();
          p.RCW();
          p.FCCW();
        }
        // case 34
        else if (front[1] == up[4] && left[0] == up[4] && right[2] == up[4] && back[1] == up[4] && up[3] == up[4] && up[5] == up[4] && up[6] == up[4] && up[8] == up[4]) {
          p.RCW();
          p.UCW();
          p.RCW();
          p.RCW();
          p.UCCW();
          p.RCCW();
          p.FCW();
          p.RCW();
          p.UCW();
          p.RCW();
          p.UCCW();
          p.FCCW();
        }
        // case 35
        else if (front[0] == up[4] && left[1] == up[4] && right[2] == up[4] && back[1] == up[4] && up[0] == up[4] && up[5] == up[4] && up[7] == up[4] && up[8] == up[4]) {
          p.RCW();
          p.UCW();
          p.UCW();
          p.RCW();
          p.RCW();
          p.FCW();
          p.RCW();
          p.FCCW();
          p.RCW();
          p.UCW();
          p.UCW();
          p.RCCW();
        }
        // case 36
        else if (front[0] == up[4] && left[1] == up[4] && left[2] == up[4] && back[0] == up[4] && up[0] == up[4] && up[1] == up[4] && up[5] == up[4] && up[8] == up[4]) {
          p.LCCW();
          p.UCCW();
          p.LCW();
          p.UCCW();
          p.LCCW();
          p.UCW();
          p.LCW();
          p.UCW();
          p.LCW();
          p.FCCW();
          p.LCCW();
          p.FCW();
        }
        // case 37
        else if (front[0] == up[4] && front[1] == up[4] && right[1] == up[4] && right[2] == up[4] && up[0] == up[4] && up[1] == up[4] && up[3] == up[4] && up[8] == up[4]) {
          p.FCW();
          p.RCCW();
          p.FCCW();
          p.RCW();
          p.UCW();
          p.RCW();
          p.UCCW();
          p.RCCW();
        }
        // case 38
        else if (front[1] == up[4] && right[0] == up[4] && right[1] == up[4] && back[2] == up[4] && up[1] == up[4] && up[2] == up[4] && up[3] == up[4] && up[6] == up[4]) {
          p.RCW();
          p.UCW();
          p.RCCW();
          p.UCW();
          p.RCW();
          p.UCCW();
          p.RCCW();
          p.UCCW();
          p.RCCW();
          p.FCW();
          p.RCW();
          p.FCCW();
        }
        // case 39
        else if (front[1] == up[4] && right[0] == up[4] && back[1] == up[4] && back[2] == up[4] && up[2] == up[4] && up[3] == up[4] && up[5] == up[4] && up[6] == up[4]) {
          p.LCW();
          p.FCCW();
          p.LCCW();
          p.UCCW();
          p.LCW();
          p.UCW();
          p.FCW();
          p.UCCW();
          p.LCCW();
        }
        // case 40
        else if (front[1] == up[4] && left[2] == up[4] && back[0] == up[4] && back[1] == up[4] && up[0] == up[4] && up[3] == up[4] && up[5] == up[4] && up[8] == up[4]) {
          p.RCCW();
          p.FCW();
          p.RCW();
          p.UCW();
          p.RCCW();
          p.UCCW();
          p.FCCW();
          p.UCW();
          p.RCW();
        }
        // case 41
        else if (front[1] == up[4] && right[1] == up[4] && back[0] == up[4] && back[2] == up[4] && up[1] == up[4] && up[3] == up[4] && up[6] == up[4] && up[8] == up[4]) {
          p.RCW();
          p.UCW();
          p.RCCW();
          p.UCW();
          p.RCW();
          p.UCW();
          p.UCW();
          p.RCCW();
          p.FCW();
          p.RCW();
          p.UCW();
          p.RCCW();
          p.UCCW();
          p.FCCW();
        }
        // case 42
        else if (front[0] == up[4] && front[2] == up[4] && right[1] == up[4] && back[1] == up[4] && up[0] == up[4] && up[2] == up[4] && up[3] == up[4] && up[7] == up[4]) {
          p.RCCW();
          p.UCCW();
          p.RCW();
          p.UCCW();
          p.RCCW();
          p.UCW();
          p.UCW();
          p.RCW();
          p.FCW();
          p.RCW();
          p.UCW();
          p.RCCW();
          p.UCCW();
          p.FCCW();
        }
        // case 43
        else if (front[1] == up[4] && left[0] == up[4] && left[1] == up[4] && left[2] == up[4] && up[1] == up[4] && up[2] == up[4] && up[5] == up[4] && up[8] == up[4]) {
          p.FCCW();
          p.UCCW();
          p.LCCW();
          p.UCW();
          p.LCW();
          p.FCW();
        }
        // case 44
        else if (front[1] == up[4] && right[0] == up[4] && right[1] == up[4] && right[2] == up[4] && up[0] == up[4] && up[1] == up[4] && up[3] == up[4] && up[6] == up[4]) {
          p.FCW();
          p.UCW();
          p.RCW();
          p.UCCW();
          p.RCCW();
          p.FCCW();
        }
        // case 45
        else if (front[1] == up[4] && left[0] == up[4] && left[2] == up[4] && back[1] == up[4] && up[2] == up[4] && up[3] == up[4] && up[5] == up[4] && up[8] == up[4]) {
          p.FCW();
          p.RCW();
          p.UCW();
          p.RCCW();
          p.UCCW();
          p.FCCW();
        }
        // case 46
        else if (left[1] == up[4] && right[0] == up[4] && right[1] == up[4] && right[2] == up[4] && up[0] == up[4] && up[1] == up[4] && up[6] == up[4] && up[7] == up[4]) {
          p.RCCW();
          p.UCCW();
          p.RCCW();
          p.FCW();
          p.RCW();
          p.FCCW();
          p.UCW();
          p.RCW();
        }
        // case 47
        else if (front[0] == up[4] && front[1] == up[4] && left[1] == up[4] && right[0] == up[4] && right[2] == up[4] && back[2] == up[4] && up[1] == up[4] && up[5] == up[4]) {
          p.RCCW();
          p.UCCW();
          p.RCCW();
          p.FCW();
          p.RCW();
          p.FCCW();
          p.RCCW();
          p.FCW();
          p.RCW();
          p.FCCW();
          p.UCW();
          p.RCW();
        }
        // case 48
        else if (front[1] == up[4] && front[2] == up[4] && left[0] == up[4] && left[2] == up[4] && right[1] == up[4] && back[0] == up[4] && up[1] == up[4] && up[3] == up[4]) {
          p.FCW();
          p.RCW();
          p.UCW();
          p.RCCW();
          p.UCCW();
          p.RCW();
          p.UCW();
          p.RCCW();
          p.UCCW();
          p.FCCW();
        }
        // case 49
        else if (front[1] == up[4] && front[2] == up[4] && left[0] == up[4] && left[1] == up[4] && left[2] == up[4] && back[0] == up[4] && up[1] == up[4] && up[5] == up[4]) {
          p.rCW();
          p.UCCW();
          p.rCW();
          p.rCW();
          p.UCW();
          p.rCW();
          p.rCW();
          p.UCW();
          p.rCW();
          p.rCW();
          p.UCCW();
          p.rCW();
        }
        // case 50
        else if (front[2] == up[4] && left[0] == up[4] && left[1] == up[4] && left[2] == up[4] && back[0] == up[4] && back[1] == up[4] && up[5] == up[4] && up[7] == up[4]) {
          p.rCCW();
          p.UCW();
          p.rCW();
          p.rCW();
          p.UCCW();
          p.rCW();
          p.rCW();
          p.UCCW();
          p.rCW();
          p.rCW();
          p.UCW();
          p.rCCW();
        }
        // case 51
        else if (front[0] == up[4] && front[1] == up[4] && right[0] == up[4] && right[2] == up[4] && back[1] == up[4] && back[2] == up[4] && up[3] == up[4] && up[5] == up[4]) {
          p.FCW();
          p.UCW();
          p.RCW();
          p.UCCW();
          p.RCCW();
          p.UCW();
          p.RCW();
          p.UCCW();
          p.RCCW();
          p.FCCW();
        }
        // case 52
        else if (front[0] == up[4] && left[1] == up[4] && right[0] == up[4] && right[1] == up[4] && right[2] == up[4] && back[2] == up[4] && up[1] == up[4] && up[7] == up[4]) {
          p.RCW();
          p.UCW();
          p.RCCW();
          p.UCW();
          p.RCW();
          p.UCCW();
          p.BCW();
          p.UCCW();
          p.BCCW();
          p.RCCW();
        }
        // case 53
        else if (front[0] == up[4] && front[1] == up[4] && front[2] == up[4] && left[1] == up[4] && back[0] == up[4] && back[2] == up[4] && up[1] == up[4] && up[5] == up[4]) {
          p.lCCW();
          p.UCW();
          p.UCW();
          p.LCW();
          p.UCW();
          p.LCCW();
          p.UCCW();
          p.LCW();
          p.UCW();
          p.LCCW();
          p.UCW();
          p.lCW();
        }
        // case 54
        else if (front[0] == up[4] && front[1] == up[4] && front[2] == up[4] && right[1] == up[4] && back[0] == up[4] && back[2] == up[4] && up[1] == up[4] && up[3] == up[4]) {
          p.rCW();
          p.UCW();
          p.UCW();
          p.RCCW();
          p.UCCW();
          p.RCW();
          p.UCW();
          p.RCCW();
          p.UCCW();
          p.RCW();
          p.UCCW();
          p.rCCW();
        }
        // case 55
        else if (front[0] == up[4] && front[1] == up[4] && front[2] == up[4] && back[0] == up[4] && back[1] == up[4] && back[2] == up[4] && up[3] == up[4] && up[5] == up[4]) {
          p.RCCW();
          p.FCW();
          p.RCW();
          p.UCW();
          p.RCW();
          p.UCCW();
          p.RCW();
          p.RCW();
          p.FCCW();
          p.RCW();
          p.RCW();
          p.UCCW();
          p.RCCW();
          p.UCW();
          p.RCW();
          p.UCW();
          p.RCCW();
        }
        // case 56
        else if (front[1] == up[4] && left[0] == up[4] && left[2] == up[4] && right[0] == up[4] && right[2] == up[4] && back[1] == up[4] && up[3] == up[4] && up[5] == up[4]) {
          p.rCCW();
          p.UCCW();
          p.rCW();
          p.UCCW();
          p.RCCW();
          p.UCW();
          p.RCW();
          p.UCCW();
          p.RCCW();
          p.UCW();
          p.RCW();
          p.rCCW();
          p.UCW();
          p.rCW();
        }
        // case 57
        else if (front[1] == up[4] && back[1] == up[4] && up[0] == up[4] && up[2] == up[4] && up[3] == up[4] && up[5] == up[4] && up[6] == up[4] && up[8] == up[4]) {
          p.RCW();
          p.UCW();
          p.RCCW();
          p.UCCW();
          p.MCCW();
          p.UCW();
          p.RCW();
          p.UCCW();
          p.rCCW();
        }
        // turn cube
        else {
          p.UCW();
        }
      }
    }
  }

  void PLL() {
    for (int k = 0; k < 4; k++) {
      if (front[0] != front[1] || front[0] != front[2] || left[0] != left[1] || left[0] != left[2] || right[0] != right[1] || right[0] != right[2] || back[0] != back[1] || back[0] != back[2]) {
        //case Aa
        if (front[0] == left[1] && front[0] == right[2] && front[1] == front[2] && front[1] == back[0] && left[0] == left[2] && left[0] == back[1] && right[0] == right[1] && right[0] == back[2]) {
          p.XCW();
          p.LCW();
          p.LCW();
          p.DCW();
          p.DCW();
          p.LCCW();
          p.UCCW();
          p.LCW();
          p.DCW();
          p.DCW();
          p.LCCW();
          p.UCW();
          p.LCCW();
          p.XCCW();
        }
        // case Ab
        else if (front[1] == left[0] && front[1] == left[2] && front[2] == back[0] && front[2] == back[1] && front[0] == right[1] && front[0] == right[2] && right[0] == left[1] && right[0] == back[2]) {
          p.XCCW();
          p.LCW();
          p.LCW();
          p.DCW();
          p.DCW();
          p.LCW();
          p.UCW();
          p.LCCW();
          p.DCW();
          p.DCW();
          p.LCW();
          p.UCCW();
          p.LCW();
          p.XCW();
        }
        // case E
        else if (front[1] == left[0] && front[1] == right[2] && right[0] == left[2] && right[0] == back[1] && front[2] == right[1] && front[2] == back[0] && front[0] == left[1] && front[0] == back[2]) {
          p.XCCW();
          p.LCCW();
          p.UCW();
          p.LCW();
          p.DCCW();
          p.LCCW();
          p.UCCW();
          p.LCW();
          p.DCW();
          p.LCCW();
          p.UCCW();
          p.LCW();
          p.DCCW();
          p.LCCW();
          p.UCW();
          p.LCW();
          p.DCW();
          p.XCW();
        }
        // case F
        else if (front[0] == right[2] && front[0] == back[1] && front[1] == right[0] && front[1] == back[2] && front[2] == right[1] && front[2] == back[0] && left[0] == left[1] && left[0] == left[2]) {
          p.RCCW();
          p.UCCW();
          p.FCCW();
          p.RCW();
          p.UCW();
          p.RCCW();
          p.UCCW();
          p.RCCW();
          p.FCW();
          p.RCW();
          p.RCW();
          p.UCCW();
          p.RCCW();
          p.UCCW();
          p.RCW();
          p.UCW();
          p.RCCW();
          p.UCW();
          p.RCW();
        }
        // case Ga
        else if (front[0] == right[2] && front[0] == back[1] && left[1] == right[0] && left[1] == back[2] && front[1] == front[2] && front[1] == back[0] && left[0] == left[2] && left[0] == right[1]) {
          p.RCW();
          p.RCW();
          p.UCW();
          p.RCCW();
          p.UCW();
          p.RCCW();
          p.UCCW();
          p.RCW();
          p.UCCW();
          p.RCW();
          p.RCW();
          p.UCCW();
          p.DCW();
          p.RCCW();
          p.UCW();
          p.RCW();
          p.DCCW();
        }
        // case Gb
        else if (front[0] == right[1] && front[0] == right[2] && front[1] == right[0] && front[1] == back[2] && front[2] == back[0] && front[2] == left[1] && left[0] == left[2] && left[0] == back[1]) {
          p.RCCW();
          p.UCCW();
          p.RCW();
          p.UCW();
          p.DCCW();
          p.RCW();
          p.RCW();
          p.UCW();
          p.RCCW();
          p.UCW();
          p.RCW();
          p.UCCW();
          p.RCW();
          p.UCCW();
          p.RCW();
          p.RCW();
          p.DCW();
        }
        // case Gc
        else if (front[0] == left[1] && front[0] == right[2] && front[1] == right[0] && front[1] == back[2] && front[2] == back[0] && front[2] == back[1] && left[0] == left[2] && left[0] == right[1]) {
          p.RCW();
          p.RCW();
          p.UCCW();
          p.RCW();
          p.UCCW();
          p.RCW();
          p.UCW();
          p.RCCW();
          p.UCW();
          p.RCW();
          p.RCW();
          p.UCW();
          p.DCCW();
          p.RCW();
          p.UCCW();
          p.RCCW();
          p.DCW();
        }
        // case Gd
        else if (front[0] == right[2] && front[0] == back[1] && right[0] == right[1] && right[0] == back[2] && front[2] == left[1] && front[2] == back[0] && front[1] == left[0] && front[1] == left[2]) {
          p.RCW();
          p.UCW();
          p.RCCW();
          p.UCCW();
          p.DCW();
          p.RCW();
          p.RCW();
          p.UCCW();
          p.RCW();
          p.UCCW();
          p.RCCW();
          p.UCW();
          p.RCCW();
          p.UCW();
          p.RCW();
          p.RCW();
          p.DCCW();
        }
        // case H
        else if (front[0] == front[2] && front[0] == back[1] && front[1] == back[0] && front[1] == back[2] && left[1] == right[0] && left[1] == right[2] && left[0] == left[2] && left[0] == right[1]) {
          p.MCW();
          p.MCW();
          p.UCW();
          p.MCW();
          p.MCW();
          p.UCW();
          p.UCW();
          p.MCW();
          p.MCW();
          p.UCW();
          p.MCW();
          p.MCW();
        }
        // Case Ja
        else if (front[0] == front[1] && front[0] == right[2] && right[0] == right[1] && right[0] == back[2] && front[2] == back[0] && front[2] == back[1] && left[0] == left[1] && left[0] == left[2]) {
          p.XCW();
          p.RCW();
          p.RCW();
          p.FCW();
          p.RCW();
          p.FCCW();
          p.RCW();
          p.UCW();
          p.UCW();
          p.rCCW();
          p.UCW();
          p.rCW();
          p.UCW();
          p.UCW();
          p.XCCW();
        }
        // Case Jb
        else if (front[1] == front[2] && front[1] == back[0] && left[0] == left[1] && left[0] == left[2] && right[0] == back[1] && right[0] == back[2] && front[0] == right[1] && front[0] == right[2]) {
          p.RCW();
          p.UCW();
          p.RCCW();
          p.FCCW();
          p.RCW();
          p.UCW();
          p.RCCW();
          p.UCCW();
          p.RCCW();
          p.FCW();
          p.RCW();
          p.RCW();
          p.UCCW();
          p.RCCW();
        }
        // Case Na
        else if (front[1] == front[2] && front[1] == back[0] && front[0] == back[1] && front[0] == back[2] && left[1] == left[2] && left[1] == right[0] && left[0] == right[1] && left[0] == right[2]) {
          p.RCW();
          p.UCW();
          p.RCCW();
          p.UCW();
          p.RCW();
          p.UCW();
          p.RCCW();
          p.FCCW();
          p.RCW();
          p.UCW();
          p.RCCW();
          p.UCCW();
          p.RCCW();
          p.FCW();
          p.RCW();
          p.RCW();
          p.UCCW();
          p.RCCW();
          p.UCW();
          p.UCW();
          p.RCW();
          p.UCCW();
          p.RCCW();
        }
        // Case Nb
        else if (front[0] == front[1] && front[0] == back[2] && front[2] == back[0] && front[2] == back[1] && left[0] == left[1] && left[0] == right[2] && left[2] == right[0] && left[2] == right[1]) {
          p.RCCW();
          p.UCW();
          p.RCW();
          p.UCCW();
          p.RCCW();
          p.FCCW();
          p.UCCW();
          p.FCW();
          p.RCW();
          p.UCW();
          p.RCCW();
          p.FCW();
          p.RCCW();
          p.FCCW();
          p.RCW();
          p.UCCW();
          p.RCW();
        }
        // Case Ra
        else if (front[2] == right[1] && front[2] == back[0] && left[0] == left[2] && left[0] == back[1] && left[1] == right[0] && left[1] == back[2] && front[0] == front[1] && front[0] == right[2]) {
          p.RCW();
          p.UCCW();
          p.RCCW();
          p.UCCW();
          p.RCW();
          p.UCW();
          p.RCW();
          p.DCW();
          p.RCCW();
          p.UCCW();
          p.RCW();
          p.DCCW();
          p.RCCW();
          p.UCW();
          p.UCW();
          p.RCCW();
        }
        // Case Rb
        else if (front[1] == left[0] && front[1] == left[2] && front[2] == right[1] && front[2] == back[0] && front[0] == left[1] && front[0] == right[2] && right[0] == back[1] && right[0] == back[2]) {
          p.RCW();
          p.RCW();
          p.FCW();
          p.RCW();
          p.UCW();
          p.RCW();
          p.UCCW();
          p.RCCW();
          p.FCCW();
          p.RCW();
          p.UCW();
          p.UCW();
          p.RCCW();
          p.UCW();
          p.UCW();
          p.RCW();
        }
        // Case T
        else if (front[0] == front[1] && front[0] == right[2] && right[0] == back[1] && right[0] == back[2] && front[2] == left[1] && front[2] == back[0] && left[0] == left[2] && left[0] == right[1]) {
          p.RCW();
          p.UCW();
          p.RCCW();
          p.UCCW();
          p.RCCW();
          p.FCW();
          p.RCW();
          p.RCW();
          p.UCCW();
          p.RCCW();
          p.UCCW();
          p.RCW();
          p.UCW();
          p.RCCW();
          p.FCCW();
        }
        // Case Ua
        else if (front[0] == front[2] && front[0] == left[1] && back[0] == back[1] && back[0] == back[2] && front[1] == right[0] && front[1] == right[2] && left[0] == left[2] && left[0] == right[1]) {
          p.MCW();
          p.MCW();
          p.UCW();
          p.MCW();
          p.UCW();
          p.UCW();
          p.MCCW();
          p.UCW();
          p.MCW();
          p.MCW();
        }
        // Case Ub
        else if (front[0] == front[2] && front[0] == right[1] && back[0] == back[1] && back[0] == back[2] && left[1] == right[0] && left[1] == right[2] && front[1] == left[0] && front[1] == left[2]) {
          p.MCW();
          p.MCW();
          p.UCCW();
          p.MCW();
          p.UCW();
          p.UCW();
          p.MCCW();
          p.UCCW();
          p.MCW();
          p.MCW();
        }
        // Case V
        else if (front[0] == front[1] && front[0] == back[2] && front[2] == right[1] && front[2] == back[0] && left[0] == right[2] && left[0] == back[1] && left[1] == left[2] && left[1] == right[0]) {
          p.RCCW();
          p.UCW();
          p.RCCW();
          p.UCCW();
          p.YCW();
          p.RCCW();
          p.FCCW();
          p.RCW();
          p.RCW();
          p.UCCW();
          p.RCCW();
          p.UCW();
          p.RCCW();
          p.FCW();
          p.RCW();
          p.FCW();
          p.YCCW();
        }
        // Case Y
        else if (front[0] == front[1] && front[0] == back[2] && front[2] == left[1] && front[2] == back[0] && left[0] == right[1] && left[0] == right[2] && left[2] == right[0] && left[2] == back[1]) {
          p.FCW();
          p.RCW();
          p.UCCW();
          p.RCCW();
          p.UCCW();
          p.RCW();
          p.UCW();
          p.RCCW();
          p.FCCW();
          p.RCW();
          p.UCW();
          p.RCCW();
          p.UCCW();
          p.RCCW();
          p.FCW();
          p.RCW();
          p.FCCW();
        }
        // Case Z
        else if (right[0] == right[2] && right[0] == back[1] && front[1] == left[0] && front[1] == left[2] && right[1] == back[0] && right[1] == back[2] && front[0] == front[2] && front[0] == left[1]) {
          p.MCCW();
          p.UCW();
          p.MCW();
          p.MCW();
          p.UCW();
          p.MCW();
          p.MCW();
          p.UCW();
          p.MCCW();
          p.UCW();
          p.UCW();
          p.MCW();
          p.MCW();
        } else {
          p.UCW();
        }
      }
    }
    for (int k = 0; k < 3; k++) {
      if (front[1] != front[4]) {
        p.UCW();
      }
    }
    p.XCW();
  }
};

#endif