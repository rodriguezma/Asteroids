
struct poly{
	esat::Vec2 *points;
};

void InitPoly(poly *p, esat::Vec2 *points){
	p->points = points;
}
