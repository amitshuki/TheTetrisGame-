#pragma once
class Shape
{
    int type;
public:
    enum Shapes { Line, LShape, Zshape, Sshape, plus, cube, Jshape };

    char Shapes[7][4][4] =
    {
{
    { '&', ' ', ' ', ' ' },
    { '&', ' ', ' ', ' ' },
    { '&', ' ', ' ', ' ' },
    { '&', ' ', ' ', ' ' }
},
{
   
    {  '&', '&', ' ',' ' },
    {  '&', ' ', ' ',' ' },
    {  '&', ' ', ' ' ,' '},
     {  ' ', ' ', ' ',' ' }
},
{
    {  '&', '&', ' ' ,' '},
    {  ' ', '&', '&',' ' },
    {  ' ', ' ', ' ',' ' },
    { ' ', ' ', ' ',' ' }
},
{
    { '&', ' ', ' ',' ' },
    { '&','&', ' ' ,' '},
    {  ' ','&', ' ',' ' },
    { ' ', ' ', ' ', ' ' }
},
{
    
    { ' ', '&', ' ', ' ' },
    { '&', '&', '&', ' ' },
    { ' ', ' ', ' ', ' ' },
    { ' ', ' ', ' ', ' ' }
},
{
    { '&', '&', ' ', ' ' },
    { '&', '&', ' ', ' ' },
    { ' ', ' ', ' ', ' ' },
    { ' ', ' ', ' ', ' ' }
},
{
    { '&', '&', ' ', ' ' },
    { ' ', '&', ' ', ' ' },
    { ' ', '&', ' ', ' ' },
    { ' ', ' ', ' ', ' ' }
}
    };
    void setShape(int shape) { type = shape; }
    int getShape() { return type; }
};

