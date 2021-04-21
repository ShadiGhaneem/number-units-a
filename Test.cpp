#include "doctest.h"
#include <string>
#include "NumberWithUnits.hpp"

using namespace std;
using namespace ariel;



TEST_CASE("TEST 1"){
    NumberWithUnits a1(32.2,"cm");
    CHECK((+a1).getNum()==32.2);
    CHECK((+a1).getUnit()=="cm");

    NumberWithUnits a2(-42,"kg");
    CHECK((+a2).getNum()==-42);
    CHECK((+a2).getUnit()=="kg");

    NumberWithUnits a3(51,"g");
    CHECK((+a3).getNum()==51);
    CHECK((+a3).getUnit()=="g");
}

TEST_CASE("TEST 2"){
    CHECK((NumberWithUnits(31,"ton")+NumberWithUnits(41,"m"))==NumberWithUnits(23.4,"cm"));
    CHECK((NumberWithUnits(1,"g")+NumberWithUnits(11,"g"))==NumberWithUnits(12.0201,"kg"));
    CHECK((NumberWithUnits(13,"kg")+NumberWithUnits(13,"g"))==NumberWithUnits(11,"kg"));
    CHECK((NumberWithUnits(123,"kg")+NumberWithUnits(171,"g"))==NumberWithUnits(1001,"kg"));
    CHECK((NumberWithUnits(2.2,"ton")+NumberWithUnits(3.7,"g"))==NumberWithUnits(2,"ton"));
    CHECK_THROWS_MESSAGE(NumberWithUnits(3,"m")+NumberWithUnits(5,"sec"),"Error");
}

TEST_CASE("TEST 3"){
    NumberWithUnits a1(1,"m") , a2(2.41,"cm") , a3(3.41,"m");
    CHECK((a1+=a2)==a3);

    NumberWithUnits b1(1,"kg") , b2(1,"kg"), b3(2000,"g");
    CHECK((b1+=b2)==b3);

    NumberWithUnits c1(2,"kg") , c2(3,"g"), c3(2.003,"kg");
    CHECK((c1+=c2)==c3);
    NumberWithUnits d1(3,"m") , d2(5,"sec");
    CHECK_THROWS_MESSAGE(d1+=d2,"Error");
}

TEST_CASE("TEST 4"){
    NumberWithUnits a(31,"cm");
    CHECK((-a).getNum()==-31);
    CHECK((-a).getUnit()=="cm");

    NumberWithUnits b(-345,"cm");
    CHECK((-b).getNum()==345);
    CHECK((-b).getUnit()=="cm");

    NumberWithUnits c(52,"sec");
    CHECK((-c).getNum()==-52);
    CHECK((-c).getUnit()=="sec");
}

TEST_CASE("TEST 5"){
    CHECK((NumberWithUnits(23,"m")-NumberWithUnits(70,"cm"))==NumberWithUnits(22.3,"m"));
    CHECK((NumberWithUnits(11,"kg")-NumberWithUnits(1,"g"))==NumberWithUnits(10.999,"kg"));
    CHECK((NumberWithUnits(1,"g")-NumberWithUnits(1,"ton"))==NumberWithUnits(-999999,"g"));
    CHECK((NumberWithUnits(12.4,"g")-NumberWithUnits(1,"g"))==NumberWithUnits(11.4,"g"));
    CHECK((NumberWithUnits(2,"ton")-NumberWithUnits(3,"g"))==NumberWithUnits(1.999997,"ton"));
    CHECK_THROWS_MESSAGE(NumberWithUnits(31.3,"m")-NumberWithUnits(5,"ton"),"Error");
}

TEST_CASE("TEST 6"){
    
    NumberWithUnits a1(3,"m") , a2(40,"cm") , a3(2.6,"m");
    CHECK((a1-=a2)==a3);

    NumberWithUnits b1(1,"g") , b2(2,"kg"), b3(-1.999,"g");
    CHECK((b1-=b2)==b3);

    NumberWithUnits c1(1,"kg") , c2(1,"g"), c3(0.999,"kg");
    CHECK((c1-=c2)==c3);

    NumberWithUnits d1(1,"g") , d2(1,"ton"), d3(-999999,"g");
    CHECK((d1-=d2)==d3);

    NumberWithUnits e1(2,"ton") , e2(1,"g"), e3(1.999999,"ton");
    CHECK((e1-=e2)==e3);

    NumberWithUnits f1(3,"m") , f2(51,"sec");
    CHECK_THROWS_MESSAGE(f1-=f2,"Error");


}

TEST_CASE("TEST 7"){
    CHECK(NumberWithUnits(6,"kg")>NumberWithUnits(5.9,"kg"));
    CHECK(NumberWithUnits(3.9,"ton")>NumberWithUnits(3000,"kg"));
    CHECK(NumberWithUnits(7000,"m")>NumberWithUnits(6.99,"km"));
    CHECK(NumberWithUnits(5501,"g")>NumberWithUnits(5.01,"kg"));
    CHECK_FALSE(NumberWithUnits(2,"hour")>NumberWithUnits(111,"min"));
}

TEST_CASE("TEST 8"){
    CHECK(NumberWithUnits(10,"kg")>=NumberWithUnits(10,"kg"));
    CHECK(NumberWithUnits(3,"ton")>=NumberWithUnits(3000,"kg"));
    CHECK(NumberWithUnits(6001,"m")>=NumberWithUnits(6,"km"));
    CHECK(NumberWithUnits(7001,"g")>=NumberWithUnits(5,"kg"));
    CHECK(NumberWithUnits(1,"hour")>=NumberWithUnits(60,"min"));
    CHECK_FALSE(NumberWithUnits(1,"hour")>=NumberWithUnits(59.1,"min"));
    CHECK_FALSE(NumberWithUnits(6001,"m")>=NumberWithUnits(6.2,"km"));
}

TEST_CASE("TEST 9"){
    CHECK_FALSE(NumberWithUnits(7.23,"g")<NumberWithUnits(5.9,"g"));
    CHECK(NumberWithUnits(3123,"kg")<NumberWithUnits(3.5,"ton"));
    CHECK(NumberWithUnits(5.423,"kg")<NumberWithUnits(6.7,"kg"));
    CHECK(NumberWithUnits(6,"km")<NumberWithUnits(6200,"m"));
    CHECK(NumberWithUnits(5,"kg")<NumberWithUnits(5001,"g"));
    CHECK_FALSE(NumberWithUnits(70.1,"min")<NumberWithUnits(1,"hour"));
}

TEST_CASE("TEST 10"){
    CHECK(NumberWithUnits(5,"kg")<=NumberWithUnits(6,"kg"));
    CHECK(NumberWithUnits(3.234,"g")<=NumberWithUnits(3.234,"g"));
    CHECK(NumberWithUnits(2.7,"km")<=NumberWithUnits(2800,"m"));
    CHECK(NumberWithUnits(1,"km")<=NumberWithUnits(1000,"m"));
    CHECK_FALSE(NumberWithUnits(73,"min")<=NumberWithUnits(105,"min"));

}

TEST_CASE("TEST 11"){
    
    CHECK(NumberWithUnits(2,"g")==NumberWithUnits(2,"g"));
    CHECK(NumberWithUnits(45,"kg")==NumberWithUnits(45000,"g"));
    CHECK(NumberWithUnits(3.1,"km")==NumberWithUnits(3100,"m"));
    CHECK(NumberWithUnits(2,"hour")==NumberWithUnits(120,"min"));
    CHECK_FALSE(NumberWithUnits(73,"min")==NumberWithUnits(105,"min"));
}

TEST_CASE("TEST 12"){
    CHECK(NumberWithUnits(1,"hour")!=NumberWithUnits(65,"min"));
    CHECK(NumberWithUnits(4,"km")!=NumberWithUnits(3999,"m"));
    CHECK(NumberWithUnits(120,"ton")!=NumberWithUnits(60,"ton"));
    CHECK(NumberWithUnits(73,"min")!=NumberWithUnits(105,"min"));
    CHECK_FALSE(NumberWithUnits(3.1,"km")!=NumberWithUnits(3100,"m"));
    CHECK_FALSE(NumberWithUnits(45,"kg")!=NumberWithUnits(45000,"g"));


}

TEST_CASE("TEST 13"){
    NumberWithUnits a(78,"g");
    NumberWithUnits b = ++a;
    CHECK(b.getNum()==79);
    CHECK(b.getUnit()=="g");
    CHECK(a.getNum()==79);
    CHECK(a.getUnit()=="g");
            
}

TEST_CASE("TEST 14"){
    NumberWithUnits a(1,"kg");
    NumberWithUnits b = a++;
    CHECK(b.getNum()==1);
    CHECK(b.getUnit()=="kg");
    CHECK(a.getNum()==2);
    CHECK(a.getUnit()=="kg");
    
}

TEST_CASE("TEST 15"){
    NumberWithUnits a(1,"cm");
    NumberWithUnits b = --a;
    CHECK(b.getNum()==0);
    CHECK(b.getUnit()=="cm");
    CHECK(a.getNum()==0);
    CHECK(a.getUnit()=="cm");
}

TEST_CASE("TEST 16"){
    NumberWithUnits a(112,"kg");
    NumberWithUnits b = a--;
    CHECK(b.getNum()==112);
    CHECK(b.getUnit()=="kg");
    CHECK(a.getNum()==111);
    CHECK(a.getUnit()=="kg");
}
