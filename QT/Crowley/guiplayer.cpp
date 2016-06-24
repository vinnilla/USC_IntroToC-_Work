#include "guiplayer.h"

GUIPlayer::GUIPlayer( Player* p ) {
  player = p;
  nameLabel = new QLabel( this );
  nameLabel->setText( player->getName() );
}
