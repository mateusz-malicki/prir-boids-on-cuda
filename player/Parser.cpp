#include "Parser.h"

Parser& Parser::GetInstance()
{
  static Parser instance;
  return instance;
};



vector<Frame> Parser::Deserialize(string filename, int& width, int& height)
{
  int level = 0;

  bool inX = false;
  bool inY = false;
  bool inNeighbours = false;
  bool inForces = false;
  bool inAlign = false;
  bool inSeparate = false;
  bool inCohesion = false;
  bool inVelocity = false;
  bool inWidth = false;
  bool inHeight = false;  

  ifstream ifs;
  ifs.open(filename.c_str(), fstream::in);
  Frame frame;
  Boid boid;  
  
  vector<int> x;
  vector<int> y;
  vector<int> neighbours;

  vector<float> fx;
  vector<float> fy;

  vector<Frame>frames;

  int index = 0;
  int frameNumber = 0;
  do
  {
    string str;
    //getline(ifs, str, ' ');
    ifs >> str;
    //ifs.get((char*)str.data(), " ");
    string tag;   
    
    //if(!str.empty()) //cout << "string: \"" << str <<"\"" << endl;

    if(str.find("{") != string::npos)
    {
      level++;
    }
    else if(str.find("}") != string::npos)
    {
      if(inForces && level == 3)
      {
        inForces = false;
      }
      if(inForces && level == 4)
      {
        if(inCohesion)
        {
          inCohesion = false;
          for(int i = 0; i < fx.size(); i++)
          {
            Vector2D vect(fx[i], fy[i]);
            frame.boids[i].cohesionForce = vect;
          }
        }
        if(inVelocity)
        {
          inVelocity = false;
          for(int i = 0; i < fx.size(); i++)
          {
            Vector2D vect(fx[i], fy[i]);
            frame.boids[i].velocityForce = vect;
          }
        }

        if(inSeparate)
        {
          inSeparate = false;
          for(int i = 0; i < fx.size(); i++)
          {
            Vector2D vect(fx[i], fy[i]);
            frame.boids[i].separateForce = vect;
          }
        }
        if(inAlign)
        {
          inAlign = false;
          for(int i = 0; i < fx.size(); i++)
          {
            Vector2D vect(fx[i], fy[i]);
            frame.boids[i].alignForce = vect;
          }
        }
        fx.clear();
        fy.clear();
      }
      level--;
    };
    
    if(str.find("[") != string::npos)
    {
      level++;
      continue;
    }
    if( str.find("]") != string::npos)
    {
      if(level == 2)
      {
        //cout << "juz!"<<endl;
        frames.push_back(frame);
        frame.boids.clear();
        index = 0;
        x.clear();
        y.clear();
        fx.clear();
        fy.clear();
        frameNumber++;
        //cout<<"frames: "<<frameNumber<<endl;
      }

      if(inNeighbours && level==5) 
      {
        frame.boids[index].neighbours = neighbours;
        //cout << "Dodalem "<<neighbours.size() <<" sasiadow boidowi nr " <<index+1<<endl;
        index++;
        neighbours.clear();
      }
      if(inNeighbours && level == 4)
      {
        inNeighbours = false;
      }

      level--;
      if(inX) inX = false;
      if(inY) inY = false;
      continue;
    };

    
    
    if(str.find("\"") != string::npos)
    {
      int  firstQuotationMark = str.find_first_of("\"");
      int secondQuotationMark = str.find_first_of("\"", firstQuotationMark+1);

      tag = str.substr(firstQuotationMark+1, secondQuotationMark-firstQuotationMark-1);
      //cout << "level: " << level << " tag: " << tag << endl;
    } 
  
    if(tag == "x")
    {
      index = 0;
      inX = true;
      continue;
    }
     

    else if(tag == "y")
    {
      index = 0;
      inY = true;
      continue;
    }
    else if(tag == "neighbours")
    {
      inNeighbours = true;
    }

    if((inX && !inNeighbours) || (inY && !inNeighbours))
    {    
      string number = str.find(",")!=string::npos ? str.substr(0, str.length()-1) : str.substr(0, str.length());
  
      if(inX) x.push_back(atoi(number.c_str()));
      else if(inY) y.push_back(atoi(number.c_str()));
      //cout <<"tada: "<<number<<endl;
    }
    if(inWidth)
    {
      string number = str.find(",")!=string::npos ? str.substr(0, str.length()-1) : str.substr(0, str.length());
      width = atoi(number.c_str());
      inWidth = false;
    }
    if(inHeight)
    {
      inHeight = false;
      string number = str.find(",")!=string::npos ? str.substr(0, str.length()-1) : str.substr(0, str.length());
      height = atoi(number.c_str());
    }


    if(tag == "neighbours")
    {
      inNeighbours = true;
      
      for(int i = 0; i < x.size(); i++) //dodaj boidy z pozycjami do ramki
      {
        frame.AddBoid(Boid(x[i], y[i]));
        //cout << "Dodałem boida nr " << i+1 << endl;
      }

      continue;
    }
   
    if(inNeighbours && level==5)
    {
      string number = str.find(",")!=string::npos ? str.substr(0, str.length()-1) : str.substr(0, str.length());
      neighbours.push_back(atoi(number.c_str()));
      //cout << "dodalem sasiada " << number.c_str() << " teraz jest ich " << neighbours.size() << endl;
    }

    if(inForces && level==5 && inX)
    {
      string number = str.find(",")!=string::npos ? str.substr(0, str.length()-1) : str.substr(0, str.length());
      
      fx.push_back(atof(number.c_str()));
    }

    if(inForces && level==5 && inY)
    {
      string number = str.find(",")!=string::npos ? str.substr(0, str.length()-1) : str.substr(0, str.length());
      
      fy.push_back(atof(number.c_str()));
    }




    if(tag == "forces")
    {
      inForces = true;
    }
  
    if(tag == "cohesion")
    {
      inCohesion = true;
    }

    if(tag == "separation")
    {
      inSeparate = true;
    }
  
    if(tag == "alignment")
    {
      inAlign = true;
    }

    if(tag == "velocity")
    {
      inVelocity = true;
    }

    if(tag == "width")
    {
      inWidth = true;
    }

    if(tag == "height")
    {
      inHeight = true;
    }

   
  }while(level > 0);
 //cout<<"zwaracam!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!"<<endl;
 return frames; 
};
