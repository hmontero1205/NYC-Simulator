class Block
{
  public:
    Block(int x, int y, int dir, int mode);
    int getX();
    int getY();
    int getMode();
    void moveTo(int x, int y);
    void drive();
   
  private:
    int xCoord;
    int yCoord;
    int dir;
    int bMode;
    
};