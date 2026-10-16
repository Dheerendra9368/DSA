/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is higher than the picked number
 *			      1 if num is lower than the picked number
 *               otherwise return 0
 * int guess(int num);
 */

class Solution {
public:
    int guessNumber(int n) {
      int pick=n;
      int x=guess(pick);
      while(x!=0){
        if(x==1){
            x=guess(pick+1);
            pick++;
        }
        else{
            x=guess(pick-1);
            pick--;
        }
      }
      return pick;
    }
};