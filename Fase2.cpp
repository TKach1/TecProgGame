#include "Fase2.h"

Fase2::Fase2(Jogador* play)
{
	HealthBar = new Ente(30);
	isComplete = false;
	initFase2(play);
}

Fase2::~Fase2()
{
	deleteFase();
}

void Fase2::initFase2(Jogador* play) {
	player = play;
	for (int i = 0; i < 10; i++) {
		plat = new Plataforma(35.f * i, 500.f);
		listEn.push(plat);
	}
	for (int i = 0; i < 4; i++) {
		plat = new Plataforma(350.f, 500.f -35.f * i);
		listEn.push(plat);
	}
	for (int i = 0; i < 15; i++) {
		plat = new Plataforma(350.f + 35.f * i, 500.f - 140.f);
		listEn.push(plat);
	}
	for (int i = 0; i < 6; i++) {
		plat = new Plataforma(875.f, 500.f - 175.f + 35.f * i);
		listEn.push(plat);
	}
	for (int i = 0; i < 60; i++) {
		plat = new Plataforma(875.f + 35.f * i, 500.f);
		listEn.push(plat);

		if (i % 15 == 0 && i > 0) {
			for (int j = 0; j < 5; j++) {
				plat = new Plataforma(875.f + 35.f * (i+j), 325.f + 70.f);
				listEn.push(plat);
			}
			serra = new Serra(875.f + 35.f * (i), 225.f + 70.f);
			listEn.push(serra);
		}
		if (i == 1) {
			vamp = new Vampiro(875.f + 35.f * i, 500.f - 40.f);
			listEn.push(vamp);
			HealthBar->mover(vamp->getIniVida(), 0);
		}
	}
	for (int i = 0; i < 10; i++) {
		plat = new Plataforma(2975.f, 500.f - 35.f * i);
		listEn.push(plat);
	}

}

void Fase2::executar() {
	player->move();
	if (listEn.percorrer(player)) {
		listEn.del();
		initFase2(player);
		player->reset();
	}
	if (vamp->isDead == true) {
		isComplete = true;
	}
	HealthBar->print(vamp->getVida());
	player->print(player->anim);
	//requisito para passar da fase 2: matar o chefe
	//todo: fazer o chefe para poder implementar aqui
}
