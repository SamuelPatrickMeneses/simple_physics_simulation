#include "./game.hpp"
#include "./config.hpp"
using game::input::keyboard;
b2Vec2 flor[2] = {b2Vec2(5.f, 2.f), b2Vec2(30.f, 1.0f)};
b2Vec2 quadb1[2] = {b2Vec2(4.f, 7.f), b2Vec2(1.f, 0.5)};
b2Vec2 quadb2[2] = {b2Vec2(5.5, 4.f), b2Vec2(0.5, 0.5)};
b2Body* volatile b1 = nullptr;
b2Body* volatile b2 = nullptr;
b2Body* volatile b3 = nullptr;


void game::lifeCicle::load(){
	glColor3ub(55, 255, 55);
	glClearColor(0, 0, 0, 0);
	b1 = createQuadBody(quadb1, true);
	b2 = createQuadBody(flor);
	b3 = createQuadBody(quadb2);
	//createCircleBody(b2Vec2(2.f, 4.f), 1.f);
	b1->SetSleepingAllowed(false);
	//b1->SetFixedRotation(true);

}
void game::lifeCicle::step(){
	// float matrix[16];
    // glGetFloatv(GL_PROJECTION_MATRIX, matrix);
    // // print(*((int*) matrix));
	// std::cout << "[";
    // if(matrix != nullptr)
    //     for(int i = 0; i < 16; i++)
    //     	std::cout << matrix[i] << " ";
    // std::cout << "]\n";

	bool pulo = b1->GetLinearVelocity().y != 0;
	b2Vec2 force(0, 0);
	print(keyboard->check(97) << " " << keyboard->check(100)<< " " << keyboard->check(32));
	if(keyboard->check(97))
		force.x -= 5;
	if(keyboard->check(100))
		force.x += 5;
	if(keyboard->check(32) && !pulo){
		pulo = true;
		//b1->SetAwake(true);
		force.y += 10;
	}
	//b1->ApplyForce(force, b1->GetLocalCenter(), true);
	if(force.x != 0 || force.y != 0)
		b1->SetLinearVelocity(force);
	//b1->ApplyLinearImpulse(force, b1->GetLocalCenter(), true);
	//b1->SetLinearVelocity(force);

}
void game::lifeCicle::unload(){

}
void game::lifeCicle::keyDown(unsigned char key, int x, int y){

}
// void game::lifeCicle::keyUp(unsigned char key, int x, int y){
	
// 	// b2Vec2 localCenter = b1->GetPosition();
// 	// print(localCenter.x <<"  "<< localCenter.y);
// 	//pulo = false;
// }
int main(int  argc, char ** argv){
	game::lifeCicle::config( argc, argv);
	game::lifeCicle::start();
	return 0;
}
