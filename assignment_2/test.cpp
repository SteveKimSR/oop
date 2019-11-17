//
// Created by 김혁진 on 2019/11/12.
//

#include "Integer.h"
#include "Float.h"
#include "Complex.h"
#include <iostream>

int main() {
    // 이번 과제는 테스트 코드를 주지 않습니다.
    // 직접 코드를 작성해보면서 확인해보세요
{    
        Number *a = new Integer(13);
        Number *result = a->add(new Float(3.14));
        std::cout << dynamic_cast<Float *>(result)->val()<<std::endl; // 16.14
 }   
 {  
        Number *a = new Integer(3);
        Number *result = a
                ->add(new Float(3.14))
                ->sub(new Integer(1))
                ->mul(new Integer(7))
                ->sub(new Complex(11, 5));

        std::cout << dynamic_cast<Complex *>(result)->to_string() << std::endl; // 24.980000 - 5.000000i
 }
    // 테스트 코드 작성해보고 확인해보세요
    // 채점은 임의의 테스트코드로 진행할 예정입니다
{	//Integer test
		Number *a = new Integer(1);
		Number *result = a->add(new Integer(1));
		std::cout << "I->I add complete" << std::endl;
		std::cout << dynamic_cast<Integer*>(result)->val() << std::endl;

		Number *b = new Integer(1);
		Number *result2 = b->add(new Float(1));
		std::cout << "I->F add complete" << std::endl;
		std::cout << dynamic_cast<Float*>(result2)->val() << std::endl;

		Number *c = new Integer(1);
		Number *result3 = c->add(new Complex(1,1));
		std::cout << "I->C add complete" << std::endl;
		std::cout << dynamic_cast<Complex*>(result3)->to_string() << std::endl;

}
{
		Number *a = new Integer(1);
		Number *result = a->sub(new Integer(1));
		std::cout << "I->I sub complete" << std::endl;
		std::cout << dynamic_cast<Integer*>(result)->val() << std::endl;

		Number *b = new Integer(1);
		Number *result2 = b->sub(new Float(1));
		std::cout << "I->F sub complete" << std::endl;
		std::cout << dynamic_cast<Float*>(result2)->val() << std::endl;

		Number *c = new Integer(1);
		Number *result3 = c->sub(new Complex(1,1));
		std::cout << "I->C sub complete" << std::endl;
		std::cout << dynamic_cast<Complex*>(result3)->to_string() << std::endl;
}
{
		Number *a = new Integer(1);
		Number *result = a->mul(new Integer(1));
		std::cout << "I->I mul complete" << std::endl;
		std::cout << dynamic_cast<Integer*>(result)->val() << std::endl;

		Number *b = new Integer(1);
		Number *result2 = b->mul(new Float(1));
		std::cout << "I->F mul complete" << std::endl;
		std::cout << dynamic_cast<Float*>(result2)->val() << std::endl;

		Number *c = new Integer(1);
		Number *result3 = c->mul(new Complex(1,1));
		std::cout << "I->C mul complete" << std::endl;
		std::cout << dynamic_cast<Complex*>(result3)->to_string() << std::endl;
}
{
		Number *a = new Integer(1);
		Number *result = a->div(new Integer(1));
		std::cout << "I->I div complete" << std::endl;
		std::cout << dynamic_cast<Integer*>(result)->val() << std::endl;

		Number *b = new Integer(1);
		Number *result2 = b->div(new Float(1));
		std::cout << "I->F div complete" << std::endl;
		std::cout << dynamic_cast<Float*>(result2)->val() << std::endl;

		Number *c = new Integer(1);
		Number *result3 = c->div(new Complex(1,1));
		std::cout << "I->C div complete" << std::endl;

}
{	//Float test
		Number *a = new Float(1);
		Number *result = a->add(new Integer(1));
		std::cout << "F->I add complete" << std::endl;
		std::cout << dynamic_cast<Float*>(result)->val() << std::endl;

		Number *b = new Float(1);
		Number *result2 = b->add(new Float(1));
		std::cout << "F->F add complete" << std::endl;
		std::cout << dynamic_cast<Float*>(result2)->val() << std::endl;

		Number *c = new Float(1);
		Number *result3 = c->add(new Complex(1,1));
		std::cout << "F->C add complete" << std::endl;
		std::cout << dynamic_cast<Complex*>(result3)->to_string() << std::endl;

}
{
		Number *a = new Float(1);
		Number *result = a->sub(new Integer(1));
		std::cout << "F->I sub complete" << std::endl;
		std::cout << dynamic_cast<Float*>(result)->val() << std::endl;

		Number *b = new Float(1);
		Number *result2 = b->sub(new Float(1));
		std::cout << "F->F sub complete" << std::endl;
		std::cout << dynamic_cast<Float*>(result2)->val() << std::endl;

		Number *c = new Float(1);
		Number *result3 = c->sub(new Complex(1,1));
		std::cout << "F->C sub complete" << std::endl;
		std::cout << dynamic_cast<Complex*>(result3)->to_string() << std::endl;

}
{
		Number *a = new Float(1);
		Number *result = a->mul(new Integer(1));
		std::cout << "F->I mul complete" << std::endl;
		std::cout << dynamic_cast<Float*>(result)->val() << std::endl;

		Number *b = new Float(1);
		Number *result2 = b->mul(new Float(1));
		std::cout << "F->F mul complete" << std::endl;
		std::cout << dynamic_cast<Float*>(result2)->val() << std::endl;

		Number *c = new Float(1);
		Number *result3 = c->mul(new Complex(1,1));
		std::cout << "F->C mul complete" << std::endl;
		std::cout << dynamic_cast<Complex*>(result3)->to_string() << std::endl;

}
{
		Number *a = new Float(1);
		Number *result = a->div(new Integer(1));
		std::cout << "F->I div complete" << std::endl;
		std::cout << dynamic_cast<Float*>(result)->val() << std::endl;

		Number *b = new Float(1);
		Number *result2 = b->div(new Float(1));
		std::cout << "F->F div complete" << std::endl;
		std::cout << dynamic_cast<Float*>(result2)->val() << std::endl;

		Number *c = new Float(1);
		Number *result3 = c->div(new Complex(1,1));
		std::cout << "F->C div complete" << std::endl;

}
{	//Complex test
		Number *a = new Complex(1,1);
		Number *result = a->add(new Integer(1));
		std::cout << "C->I add complete" << std::endl;
		std::cout << dynamic_cast<Complex*>(result)->to_string() << std::endl;

		Number *b = new Complex(1,1);
		Number *result2 = b->add(new Float(1));
		std::cout << "C->F add complete" << std::endl;
		std::cout << dynamic_cast<Complex*>(result2)->to_string() << std::endl;

		Number *c = new Complex(1,1);
		Number *result3 = c->add(new Complex(1,1));
		std::cout << "C->C add complete" << std::endl;
		std::cout << dynamic_cast<Complex*>(result3)->to_string() << std::endl;

}
{
		Number *a = new Complex(1,1);
		Number *result = a->sub(new Integer(1));
		std::cout << "C->I sub complete" << std::endl;
		std::cout << dynamic_cast<Complex*>(result)->to_string() << std::endl;

		Number *b = new Complex(1,1);
		Number *result2 = b->sub(new Float(1));
		std::cout << "C->F sub complete" << std::endl;
		std::cout << dynamic_cast<Complex*>(result2)->to_string() << std::endl;

		Number *c = new Complex(1,1);
		Number *result3 = c->sub(new Complex(1,1));
		std::cout << "C->C sub complete" << std::endl;
		std::cout << dynamic_cast<Complex*>(result3)->to_string() << std::endl;

}
{
		Number *a = new Complex(1,1);
		Number *result = a->mul(new Integer(1));
		std::cout << "C->I mul complete" << std::endl;
		std::cout << dynamic_cast<Complex*>(result)->to_string() << std::endl;

		Number *b = new Complex(1,1);
		Number *result2 = b->mul(new Float(1));
		std::cout << "C->F mul complete" << std::endl;
		std::cout << dynamic_cast<Complex*>(result2)->to_string() << std::endl;

		Number *c = new Complex(1,1);
		Number *result3 = c->mul(new Complex(1,1));
		std::cout << "C->C mul complete" << std::endl;
		std::cout << dynamic_cast<Complex*>(result3)->to_string() << std::endl;

}
{
		Number *a = new Complex(1,1);
		Number *result = a->div(new Integer(1));
		std::cout << "C->I div complete" << std::endl;
		std::cout << dynamic_cast<Complex*>(result)->to_string() << std::endl;

		Number *b = new Complex(1,1);
		Number *result2 = b->div(new Float(1));
		std::cout << "C->F div complete" << std::endl;
		std::cout << dynamic_cast<Complex*>(result2)->to_string() << std::endl;

		Number *c = new Complex(1,1);
		Number *result3 = c->div(new Complex(1,1));
		std::cout << "C->C div complete" << std::endl;

}


    return 0;
}
