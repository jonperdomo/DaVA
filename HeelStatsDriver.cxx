#include <QApplication>
#include "HeelStats.h"
 
int main( int argc, char** argv )
{
  // QT Stuff
  QApplication app( argc, argv );
 
  HeelStats HeelStats;
  HeelStats.show();
 
  return app.exec();
}
