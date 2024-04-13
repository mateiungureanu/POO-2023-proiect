#include <gtest/gtest.h>
#include <Film.h>
#include <Sala.h>
#include <Cinema.h>
#include <Bilet_Normal.h>
#include <Bilet_4Dx.h>
#include <Bilet_VIP.h>

TEST(FilmConstructor, ParametrizedConstructor)
{
    Film film("Film_Name", 8.2);
    EXPECT_EQ((double)8.2, film.getRating());
    EXPECT_EQ("Film_Name", film.getNumeFilm());
}

TEST(FilmConstructor, DefaultConstructor)
{
    Film film;
    EXPECT_EQ(0, film.getRating());
    EXPECT_EQ("", film.getNumeFilm());
}

TEST(FilmSetterGetter, RatingSetterGetter)
{
    Film film("Film_Name", 8.2);
    film.setRating(9.0);
    EXPECT_DOUBLE_EQ(9.0, film.getRating());
}

TEST(FilmSetterGetter, NumeFilmSetterGetter)
{
    Film film("Film_Name", 8.2);
    film.setNumeFilm("Film_Name_New");
    EXPECT_EQ("Film_Name_New", film.getNumeFilm());
}

TEST(FilmOperatorEqual, EqualOperator)
{
    Film film1("Film_Name", 8.2);
    Film film2("Film_Name", 8.2);
    EXPECT_TRUE(film1 == film2);
}

TEST(FilmOperatorAssignment, AssignmentOperator)
{
    Film film1("Film_Name", 8.2);
    Film film2;
    film2 = film1;
    EXPECT_TRUE(film1 == film2);
}

TEST(FilmStreamOperators, OutputOperator)
{
    Film film("Film_Name", 9.0);
    std::stringstream output;
    std::streambuf *oldCout = std::cout.rdbuf(output.rdbuf());
    std::cout << film;
    std::cout.rdbuf(oldCout);
    EXPECT_EQ("\nnume film: Film_Name (9.0)", output.str());
}

TEST(FilmComparison, LessThanOperator)
{
    Film film1("Film_Name_1", 8.0);
    Film film2("Film_Name_2", 9.0);
    EXPECT_TRUE(Film::comparaFilme(film1, film2));
    EXPECT_FALSE(Film::comparaFilme(film2, film1));
}

TEST(CinemaConstructor, ParametrizedConstructor)
{

    Cinema cinema(1, "Nume_Mall");
    EXPECT_EQ(1, cinema.getId());
    EXPECT_EQ("Nume_Mall", cinema.getNumeMall());
    EXPECT_EQ(0, cinema.getNrFilme());
    EXPECT_EQ(nullptr, cinema.getFilmeDifuzate());
}

TEST(CinemaConstructor, DefaultConstructor)
{
    Cinema cinema;
    EXPECT_EQ(0, cinema.getId());
    EXPECT_EQ("", cinema.getNumeMall());
    EXPECT_EQ(0, cinema.getNrFilme());
    EXPECT_EQ(nullptr, cinema.getFilmeDifuzate());
}

TEST(CinemaSetterGetter, IdSetterGetter)
{
    Cinema cinema;
    cinema.setId(1);
    EXPECT_EQ(1, cinema.getId());
}

TEST(CinemaSetterGetter, NumeMallSetterGetter)
{
    Cinema cinema;
    cinema.setNumeMall("Mall_Name");
    EXPECT_EQ("Mall_Name", cinema.getNumeMall());
}

TEST(CinemaSetterGetter, NrFilmeSetterGetter)
{
    Cinema cinema;
    cinema.setNrFilme(5);
    EXPECT_EQ(5, cinema.getNrFilme());
}

TEST(CinemaSetterGetter, FilmeDifuzateSetterGetter)
{
    Cinema cinema;
    Film film("Film_Name", 8.0);
    Film *filmArray = new Film[1];
    filmArray[0] = film;
    cinema.setFilmeDifuzate(1, filmArray);
    EXPECT_EQ(1, cinema.getNrFilme());
    EXPECT_EQ("Film_Name", cinema.getFilmeDifuzate()[0].getNumeFilm());
    EXPECT_EQ(8.0, cinema.getFilmeDifuzate()[0].getRating());
    delete[] filmArray;
}

TEST(CinemaAddFilm, AdaugaFilm)
{
    Cinema cinema;
    cinema.adaugaFilm("Film_Name", 8.0);
    EXPECT_EQ(1, cinema.getNrFilme());
    EXPECT_EQ("Film_Name", cinema.getFilmeDifuzate()[0].getNumeFilm());
    EXPECT_EQ(8.0, cinema.getFilmeDifuzate()[0].getRating());
}

TEST(CinemaRemoveFilm, StergeFilm)
{
    Cinema cinema;
    cinema.adaugaFilm("Film_Name", 8.0);
    cinema.stergeFilm("Film_Name");
    EXPECT_EQ(0, cinema.getNrFilme());
}

TEST(CinemaChangeRating, SchimbaRating)
{
    Cinema cinema;
    cinema.adaugaFilm("Film_Name", 8.0);
    cinema.schimbaRating("Film_Name", 9.0);
    EXPECT_EQ(9.0, cinema.getFilmeDifuzate()[0].getRating());
}

TEST(CinemaCopyConstructor, CopyConstructor)
{
    Cinema cinema1;
    cinema1.adaugaFilm("Film_Name", 8.0);
    Cinema cinema2(cinema1);
    EXPECT_EQ(1, cinema2.getNrFilme());
    EXPECT_EQ("Film_Name", cinema2.getFilmeDifuzate()[0].getNumeFilm());
    EXPECT_EQ(8.0, cinema2.getFilmeDifuzate()[0].getRating());
}

TEST(CinemaAssignmentOperator, AssignmentOperator)
{
    Cinema cinema1;
    cinema1.adaugaFilm("Film_Name_1", 8.0);
    Cinema cinema2;
    cinema2 = cinema1;
    EXPECT_EQ(1, cinema2.getNrFilme());
    EXPECT_EQ("Film_Name_1", cinema2.getFilmeDifuzate()[0].getNumeFilm());
    EXPECT_EQ(8.0, cinema2.getFilmeDifuzate()[0].getRating());
}

TEST(CinemaAdditionOperator, AdditionOperator)
{
    Cinema cinema1;
    cinema1.adaugaFilm("Film_Name_1", 8.0);
    Cinema cinema2;
    cinema2.adaugaFilm("Film_Name_1", 8.0);
    cinema2.adaugaFilm("Film_Name_2", 9.0);
    Cinema cinema3 = cinema1 + cinema2;
    EXPECT_EQ(2, cinema3.getNrFilme());
    EXPECT_EQ("Film_Name_1", cinema3.getFilmeDifuzate()[0].getNumeFilm());
    EXPECT_EQ(8.0, cinema3.getFilmeDifuzate()[0].getRating());
    EXPECT_EQ("Film_Name_2", cinema3.getFilmeDifuzate()[1].getNumeFilm());
    EXPECT_EQ(9.0, cinema3.getFilmeDifuzate()[1].getRating());
}

TEST(CinemaStreamOperators, InputOperator)
{
    std::istringstream input("1 Mall_Name 5");
    Cinema cinema;
    input >> cinema;
    EXPECT_EQ(1, cinema.getId());
    EXPECT_EQ("Mall_Name", cinema.getNumeMall());
    EXPECT_EQ(5, cinema.getNrFilme());
}

TEST(CinemaStreamOperators, OutputOperator)
{
    Cinema cinema(1, "Mall_Name");
    cinema.setNrFilme(5);
    std::ostringstream output;
    std::streambuf *oldCout = std::cout.rdbuf(output.rdbuf());
    std::cout << cinema;
    std::cout.rdbuf(oldCout);
    EXPECT_EQ("\nid: 1 nume mall: Mall_Name numar sali: 5", output.str());
}

TEST(SalaConstructor, ParameterizedConstructor)
{
    Sala sala(1);
    EXPECT_EQ(1, sala.getIdSala());
    EXPECT_EQ(63, sala.getNrLocuri());
    EXPECT_EQ(9, sala.getNrRanduri());
    EXPECT_EQ(7, sala.getNrColoane());
    EXPECT_NE(nullptr, sala.getLocuriOcupate());
}

TEST(SalaConstructor, DefaultConstructor)
{
    Sala sala;
    EXPECT_EQ(0, sala.getIdSala());
    EXPECT_EQ(0, sala.getNrLocuri());
    EXPECT_EQ(0, sala.getNrRanduri());
    EXPECT_EQ(0, sala.getNrColoane());
    EXPECT_EQ(nullptr, sala.getLocuriOcupate());
}

TEST(SalaCopyConstructor, CopyConstructor)
{
    Sala sala1(1);
    bool *locuriOcupate = new bool[63];
    sala1.setLocuriOcupate(63, locuriOcupate);
    Sala sala2(sala1);
    EXPECT_EQ(sala1.getIdSala(), sala2.getIdSala());
    EXPECT_EQ(sala1.getNrLocuri(), sala2.getNrLocuri());
    EXPECT_NE(sala1.getLocuriOcupate(), sala2.getLocuriOcupate());
}

TEST(SalaAssignmentOperator, AssignmentOperator)
{
    Sala sala1(1);
    bool *locuriOcupate = new bool[63];
    sala1.setLocuriOcupate(63, locuriOcupate);
    Sala sala2;
    sala2 = sala1;
    EXPECT_EQ(sala1.getIdSala(), sala2.getIdSala());
    EXPECT_EQ(sala1.getNrLocuri(), sala2.getNrLocuri());
    EXPECT_NE(sala1.getLocuriOcupate(), sala2.getLocuriOcupate());
}

TEST(SalaSetterGetter, IdSalaSetterGetter)
{
    Sala sala;
    sala.setIdSala(1);
    EXPECT_EQ(1, sala.getIdSala());
}

TEST(SalaSetterGetter, LocuriOcupateSetterGetter)
{
    Sala sala;
    bool *locuriOcupate = new bool[63];
    sala.setLocuriOcupate(63, locuriOcupate);
    EXPECT_NE(nullptr, sala.getLocuriOcupate());
}

TEST(BiletNormalConstructor, ParameterizedConstructor)
{
    Bilet_Normal bilet(3, 5);
    EXPECT_EQ(3, bilet.getRand());
    EXPECT_EQ(5, bilet.getColoana());
    EXPECT_EQ(25, bilet.getPret());
}

TEST(BiletNormalConstructor, DefaultConstructor)
{
    Bilet_Normal bilet;
    EXPECT_EQ(0, bilet.getRand());
    EXPECT_EQ(0, bilet.getColoana());
    EXPECT_EQ(25, bilet.getPret());
}

TEST(BiletNormalSetterGetter, RandSetterGetter)
{
    Bilet_Normal bilet;
    bilet.setRand(7);
    EXPECT_EQ(7, bilet.getRand());
}

TEST(BiletNormalSetterGetter, ColoanaSetterGetter)
{
    Bilet_Normal bilet;
    bilet.setColoana(3);
    EXPECT_EQ(3, bilet.getColoana());
}

TEST(BiletNormalSetterGetter, PretSetterGetter)
{
    Bilet_Normal bilet;
    bilet.setPret(30);
    EXPECT_EQ(30, bilet.getPret());
}

TEST(BiletNormalCopyConstructor, CopyConstructor)
{
    Bilet_Normal bilet(2, 4);
    Bilet_Normal copyBilet(bilet);
    EXPECT_EQ(bilet.getRand(), copyBilet.getRand());
    EXPECT_EQ(bilet.getColoana(), copyBilet.getColoana());
    EXPECT_EQ(bilet.getPret(), copyBilet.getPret());
}

TEST(BiletNormalAssignmentOperator, AssignmentOperator)
{
    Bilet_Normal bilet1(3, 6);
    Bilet_Normal bilet2;
    bilet2 = bilet1;
    EXPECT_EQ(bilet1.getRand(), bilet2.getRand());
    EXPECT_EQ(bilet1.getColoana(), bilet2.getColoana());
    EXPECT_EQ(bilet1.getPret(), bilet2.getPret());
}

TEST(BiletNormalAfiseaza, AfiseazaFunction)
{
    Bilet_Normal bilet(2, 3);
    testing::internal::CaptureStdout();
    bilet.afiseaza();
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ("Bilet Normal | Rand: 2, Loc: 3 | Pret: 25", output);
}

TEST(BiletNormalGetType, GetTypeFunction)
{
    Bilet_Normal bilet;
    EXPECT_EQ("Normal", bilet.getType());
}

TEST(BiletNormalDowngradeBilet, DowngradeBiletFunction)
{
    std::unique_ptr<Bilet_Normal> biletPtr = Bilet_Normal::downgradeBilet(4, 8);
    EXPECT_EQ(4, biletPtr->getRand());
    EXPECT_EQ(8, biletPtr->getColoana());
    EXPECT_EQ(25, biletPtr->getPret());
}

TEST(Bilet4DxConstructor, ParameterizedConstructorWithScaunMiscatorSuflator)
{
    Bilet_4Dx bilet(3, 5, true, false);
    EXPECT_EQ(3, bilet.getRand());
    EXPECT_EQ(5, bilet.getColoana());
    EXPECT_TRUE(bilet.getScaunMiscator());
    EXPECT_FALSE(bilet.getScaunSuflator());
    EXPECT_EQ(45, bilet.getPret());
}

TEST(Bilet4DxConstructor, ParameterizedConstructorWithoutScaunMiscatorSuflator)
{
    Bilet_4Dx bilet(3, 5);
    EXPECT_EQ(3, bilet.getRand());
    EXPECT_EQ(5, bilet.getColoana());
    EXPECT_TRUE(bilet.getScaunMiscator());
    EXPECT_TRUE(bilet.getScaunSuflator());
    EXPECT_EQ(45, bilet.getPret());
}

TEST(Bilet4DxConstructor, DefaultConstructor)
{
    Bilet_4Dx bilet;
    EXPECT_EQ(0, bilet.getRand());
    EXPECT_EQ(0, bilet.getColoana());
    EXPECT_TRUE(bilet.getScaunMiscator());
    EXPECT_TRUE(bilet.getScaunSuflator());
    EXPECT_EQ(45, bilet.getPret());
}

TEST(Bilet4DxSetterGetter, ScaunMiscatorSetterGetter)
{
    Bilet_4Dx bilet;
    bilet.setScaunMiscator(false);
    EXPECT_FALSE(bilet.getScaunMiscator());
}

TEST(Bilet4DxSetterGetter, ScaunSuflatorSetterGetter)
{
    Bilet_4Dx bilet;
    bilet.setScaunSuflator(false);
    EXPECT_FALSE(bilet.getScaunSuflator());
}

TEST(Bilet4DxSetterGetter, Pret4DxSetterGetter)
{
    Bilet_4Dx bilet;
    bilet.setPret4Dx(50);
    EXPECT_EQ(50, bilet.getPret());
}

TEST(Bilet4DxCopyConstructor, CopyConstructor)
{
    Bilet_4Dx bilet(2, 4, true, false);
    Bilet_4Dx copyBilet(bilet);
    EXPECT_EQ(bilet.getRand(), copyBilet.getRand());
    EXPECT_EQ(bilet.getColoana(), copyBilet.getColoana());
    EXPECT_EQ(bilet.getPret(), copyBilet.getPret());
    EXPECT_EQ(bilet.getScaunMiscator(), copyBilet.getScaunMiscator());
    EXPECT_EQ(bilet.getScaunSuflator(), copyBilet.getScaunSuflator());
}

TEST(Bilet4DxAssignmentOperator, AssignmentOperator)
{
    Bilet_4Dx bilet1(3, 6, true, false);
    Bilet_4Dx bilet2;
    bilet2 = bilet1;
    EXPECT_EQ(bilet1.getRand(), bilet2.getRand());
    EXPECT_EQ(bilet1.getColoana(), bilet2.getColoana());
    EXPECT_EQ(bilet1.getPret(), bilet2.getPret());
    EXPECT_EQ(bilet1.getScaunMiscator(), bilet2.getScaunMiscator());
    EXPECT_EQ(bilet1.getScaunSuflator(), bilet2.getScaunSuflator());
}

TEST(Bilet4DxAfiseaza, AfiseazaFunction)
{
    Bilet_4Dx bilet(2, 3, true, false);
    testing::internal::CaptureStdout();
    bilet.afiseaza();
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ("Bilet 4Dx    | Rand: 2, Loc: 3 | Pret: 45 | Bonus-uri 4Dx: scaun_miscator", output);
}

TEST(Bilet4DxGetType, GetTypeFunction)
{
    Bilet_4Dx bilet;
    EXPECT_EQ("4Dx", bilet.getType());
}

TEST(Bilet4DxUpgradeBilet4Dx, UpgradeBilet4DxFunction)
{
    std::unique_ptr<Bilet_4Dx> biletPtr = Bilet_4Dx::upgradeBilet4Dx(4, 8);
    EXPECT_EQ(4, biletPtr->getRand());
    EXPECT_EQ(8, biletPtr->getColoana());
    EXPECT_TRUE(biletPtr->getScaunMiscator());
    EXPECT_TRUE(biletPtr->getScaunSuflator());
    EXPECT_EQ(45, biletPtr->getPret());
}

TEST(BiletVIPConstructor, ParameterizedConstructorWithPopcornBauturiGratis)
{
    Bilet_VIP bilet(2, 3, true, false);
    EXPECT_EQ(2, bilet.getRand());
    EXPECT_EQ(3, bilet.getColoana());
    EXPECT_TRUE(bilet.getPopcornGratis());
    EXPECT_FALSE(bilet.getBauturiGratis());
    EXPECT_EQ(60, bilet.getPret());
}

TEST(BiletVIPConstructor, ParameterizedConstructorWithoutPopcornBauturiGratis)
{
    Bilet_VIP bilet(2, 3, true, false);
    EXPECT_EQ(2, bilet.getRand());
    EXPECT_EQ(3, bilet.getColoana());
    EXPECT_TRUE(bilet.getPopcornGratis());
    EXPECT_FALSE(bilet.getBauturiGratis());
    EXPECT_EQ(60, bilet.getPret());
}

TEST(BiletVIPConstructor, DefaultConstructor)
{
    Bilet_VIP bilet;
    EXPECT_EQ(0, bilet.getRand());
    EXPECT_EQ(0, bilet.getColoana());
    EXPECT_TRUE(bilet.getPopcornGratis());
    EXPECT_TRUE(bilet.getBauturiGratis());
    EXPECT_EQ(60, bilet.getPret());
}

TEST(BiletVIPSetterGetter, PopcornGratisSetterGetter)
{
    Bilet_VIP bilet;
    bilet.setPopcornGratis(false);
    EXPECT_FALSE(bilet.getPopcornGratis());
}

TEST(BiletVIPSetterGetter, BauturiGratisSetterGetter)
{
    Bilet_VIP bilet;
    bilet.setBauturiGratis(false);
    EXPECT_FALSE(bilet.getBauturiGratis());
}

TEST(BiletVIPSetterGetter, PretVIPSetterGetter)
{
    Bilet_VIP bilet;
    bilet.setPretVIP(70);
    EXPECT_EQ(70, bilet.getPret());
}

TEST(BiletVIPCopyConstructor, CopyConstructor)
{
    Bilet_VIP bilet(2, 3, true, false);
    Bilet_VIP biletCopy(bilet);
    EXPECT_EQ(bilet.getRand(), biletCopy.getRand());
    EXPECT_EQ(bilet.getColoana(), biletCopy.getColoana());
    EXPECT_EQ(bilet.getPopcornGratis(), biletCopy.getPopcornGratis());
    EXPECT_EQ(bilet.getBauturiGratis(), biletCopy.getBauturiGratis());
    EXPECT_EQ(bilet.getPret(), biletCopy.getPret());
}

TEST(BiletVIPAssignmentOperator, AssignmentOperator)
{
    Bilet_VIP bilet(2, 3, true, false);
    Bilet_VIP biletCopy;
    biletCopy = bilet;
    EXPECT_EQ(bilet.getRand(), biletCopy.getRand());
    EXPECT_EQ(bilet.getColoana(), biletCopy.getColoana());
    EXPECT_EQ(bilet.getPopcornGratis(), biletCopy.getPopcornGratis());
    EXPECT_EQ(bilet.getBauturiGratis(), biletCopy.getBauturiGratis());
    EXPECT_EQ(bilet.getPret(), biletCopy.getPret());
}

TEST(BiletVIPAfiseaza, AfiseazaFunction)
{
    Bilet_VIP bilet(2, 3, true, false);
    testing::internal::CaptureStdout();
    bilet.afiseaza();
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ("Bilet VIP    | Rand: 2, Loc: 3 | Pret: 60 | Bonus-uri VIP: popcorn_gratis", output);
}

TEST(BiletVIPGetType, GetTypeFunction)
{
    Bilet_VIP bilet;
    EXPECT_EQ("VIP", bilet.getType());
}

TEST(BiletVIPUpgradeBilet4Dx, UpgradeBiletVIPFunction)
{
    std::unique_ptr<Bilet_VIP> biletPtr = Bilet_VIP::upgradeBiletVIP(4, 8);
    EXPECT_EQ(4, biletPtr->getRand());
    EXPECT_EQ(8, biletPtr->getColoana());
    EXPECT_TRUE(biletPtr->getPopcornGratis());
    EXPECT_TRUE(biletPtr->getBauturiGratis());
    EXPECT_EQ(60, biletPtr->getPret());
}