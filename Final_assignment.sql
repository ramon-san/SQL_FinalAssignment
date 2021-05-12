CREATE TABLE pf_userType(
    user_type_id INT PRIMARY KEY NOT NULL AUTO_INCREMENT,
    type VARCHAR(20) NOT NULL
);


CREATE TABLE pf_employees(
    employee_id INT PRIMARY KEY NOT NULL AUTO_INCREMENT,
    name VARCHAR(30) NOT NULL,
    father_surname VARCHAR(30) NOT NULL,
    mother_surname VARCHAR (30) NOT NULL,
    date_of_birth DATE NOT NULL,
    phone_number VARCHAR(10) NOT NULL,
    email VARCHAR (30) NOT NULL,
    password VARCHAR(10) NOT NULL,
    user_type_id INT REFERENCES pf_userType(user_type_id) ON DELETE CASCADE ON UPDATE CASCADE
);

CREATE TABLE pf_patients(
    patient_id INT PRIMARY KEY NOT NULL AUTO_INCREMENT,
    name VARCHAR(30) NOT NULL,
    father_surname VARCHAR(30) NOT NULL,
    mother_surname VARCHAR (30) NOT NULL,
    date_of_birth DATE NOT NULL,
    phone_number VARCHAR(10) NOT NULL,
    email VARCHAR (30) NOT NULL
);

CREATE TABLE pf_searches(
    search_id INT PRIMARY KEY NOT NULL AUTO_INCREMENT,
    search VARCHAR(30) NOT NULL,
    date_of_search DATE NOT NULL,
    employee_id int REFERENCES pf_employees(employee_id) ON DELETE CASCADE ON UPDATE CASCADE
);

CREATE TABLE pf_consultations(
    consult_id INT PRIMARY KEY NOT NULL AUTO_INCREMENT,
    diagnosis VARCHAR(70) NOT NULL,
    date_of_consultation DATE NOT NULL,
    blood_pressure INT NOT NULL,
    oxygen_level INT NOT NULL,
    treatment VARCHAR(70) NOT NULL,
    cost INT NOT NULL,
    employee_id int REFERENCES pf_employees(employee_id) ON DELETE CASCADE ON UPDATE CASCADE,
    patient_id int REFERENCES pf_patients(patient_id) ON DELETE CASCADE ON UPDATE CASCADE
);

CREATE TABLE pf_vaccines(
    vaccine_id INT PRIMARY KEY NOT NULL AUTO_INCREMENT,
    vaccine VARCHAR(30) NOT NULL,
    cost INT NOT NULL
);

CREATE TABLE pf_patientsVaccines(
    patients_vaccines_id INT PRIMARY KEY NOT NULL AUTO_INCREMENT,
    date_of_vaccine DATE NOT NULL,
    patient_id int REFERENCES pf_patients(patient_id) ON DELETE CASCADE ON UPDATE CASCADE,
    vaccine_id int REFERENCES pf_vaccines(vaccines_id) ON DELETE CASCADE ON UPDATE CASCADE
);


INSERT INTO pf_userType VALUES(1, 'Doctor');
INSERT INTO pf_userType VALUES(2, 'Admin');

INSERT INTO pf_employees VALUES(1, 'Daenerys', 'Targaryen', 'Clarke', '1997/11/11', 5571836103, 'd.targaryen@7kingdoms.com', 'Drogon', 1);
INSERT INTO pf_employees VALUES(2, 'Jon', 'Snow', 'Harington', '1999/12/15', 5520194729, 'j.snow@7kingdoms.com', 'Rhaegal',	1);
INSERT INTO pf_employees VALUES(3,'Arya', 'Stark', 'Williams', '1996/1/14', 5519371129, 'a.stark@7kingdoms.com', 'Viserion', 1);
INSERT INTO pf_employees VALUES(4,'Sansa', 'Stark', 'Turner', '1993/10/08', 5513412291, 's.stark@7kingdoms.com', 'Ghost', 1);
INSERT INTO pf_employees VALUES(5,'Tyrion', 'Lannister', 'Dinklage', '1998/12/09', 5567776854, 't.lannister@7kingdoms.com', 'Nymeria',2);
INSERT INTO pf_employees VALUES(6,'Khal', 'Drogo', 'Momoa', '1995/06/10', 5519371692, 'k.drogo@7kingdoms.com', 'Greywind',	2);


INSERT INTO pf_patients VALUES(1, 'Eddard', 'Stark', 'Bean', '1987/09/07', 5567928716, 'eddardstark@hotmail.com');
INSERT INTO pf_patients VALUES(2, 'Cersei', 'Lannister', 'Headey', '1998/03/19', 5518301837, 'clannister@gmail.com');
INSERT INTO pf_patients VALUES(3, 'Joffrey', 'Baratheon', 'Gleeson', '2001/01/18',	5518910739,'joffreybaratheon@hotmail.com');
INSERT INTO pf_patients VALUES(4, 'Robb', 'Stark', 'Madden', '2014/10/13', 5518201837, 'robbstark@yahoo.com');
INSERT INTO pf_patients VALUES(5, 'Ramsay', 'Bolton', 'Rheon', '1993/05/01', 5517391738, 'rbolton@gmail.com');
INSERT INTO pf_patients VALUES(6, 'Oberyn', 'Martell', 'Pascal', '1999/01/02',	5565517367, 'omartell@gmail.com');
INSERT INTO pf_patients VALUES(7, 'Jojen', 'Reed', 'Brodie', '2006/11/03',	5512319076, 'jojenreed@hotmail.com');
INSERT INTO pf_patients VALUES(8, 'Margaery', 'Tyrell', 'Dormer', '1977/09/09', 5588192007, 'margaerytyrell@hotmail.com');
INSERT INTO pf_patients VALUES(9, 'Gregor', 'Clegane', 'Julius', '1964/11/06',	5518371192, 'gregorclegane@gmail.com');
INSERT INTO pf_patients VALUES(10, 'Daario', 'Naharis', 'Huisman', '1969/08/19', 5512812998, 'naharisdaario@hotmail.com');


INSERT INTO pf_searches VALUES(1, 'Bolton', '2021/04/30', 5);
INSERT INTO pf_searches VALUES(2, 'Bean', '2021/04/07', 5);
INSERT INTO pf_searches VALUES(3, 'Pascal', '2021/03/31', 6);
INSERT INTO pf_searches VALUES(4, 'covid', '2021/02/17', 6);
INSERT INTO pf_searches VALUES(5, 'diabetes', '2021/01/09', 5);
INSERT INTO pf_searches VALUES(6, '1964/11/06', '2020/12/08', 6);
INSERT INTO pf_searches VALUES(7, '2001/01/18', '2020/12/01', 6);


INSERT INTO pf_consultations VALUES(1, 'covid', '2021/04/30', 120, 74, 'Oxygen', 2500, 1, 1);
INSERT INTO pf_consultations VALUES(2, 'covid', '2020/07/09', 110, 84, 'Oxygen', 2500, 1, 2);
INSERT INTO pf_consultations VALUES(3, 'covid', '2020/12/27', 125, 87, 'Ibermectina', 2000, 2, 3);
INSERT INTO pf_consultations VALUES(4, 'covid', '2021/01/17', 50, 90, 'Sodium',	2000, 2, 4);
INSERT INTO pf_consultations VALUES(5, 'covid', '2020/12/17', 120, 90, 'Ibermectina', 2500, 1,	5);
INSERT INTO pf_consultations VALUES(6, 'allergy', '2021/03/14', 119, 93, 'Allergra d', 1500, 3,	6);
INSERT INTO pf_consultations VALUES(7, 'allergy', '2021/04/22',	117, 92, 'Allergra d', 1500, 4,	7);
INSERT INTO pf_consultations VALUES(8, 'allergy', '2020/10/22',	120, 95, 'Allergra d', 1000, 3,	6);
INSERT INTO pf_consultations VALUES(9, 'cold', '2020/12/11', 118, 95, 'Antibiotic', 1500, 4, 7);
INSERT INTO pf_consultations VALUES(10, 'cold', '2021/01/03', 120, 94, 'Antibiotic', 1000, 4, 8);
INSERT INTO pf_consultations VALUES(11, 'cold', '2020/11/13', 115, 96, 'Antibiotic', 1000, 3, 6);
INSERT INTO pf_consultations VALUES(12, 'diabetes', '2020/12/27', 127, 99, 'Metformin', 1200, 5, 9);
INSERT INTO pf_consultations VALUES(13, 'diabetes', '2021/02/01', 136, 98, 'Metformin',	1200, 5, 10);
INSERT INTO pf_consultations VALUES(14, 'diabetes', '2021/01/29', 140, 96, 'Metformin',	1200, 5, 9);
INSERT INTO pf_consultations VALUES(15, 'cold', '2021/04/15', 120, 99, 'Vitamin c',	600, 6,	3);
INSERT INTO pf_consultations VALUES(16, 'cold', '2021/03/03', 119, 97, 'Vitamin c',	600, 6,	5);


INSERT INTO pf_vaccines VALUES(1, 'Alin', 120);
INSERT INTO pf_vaccines VALUES(2, 'Hypack', 400);
INSERT INTO pf_vaccines VALUES(3, 'Insuline', 800);
INSERT INTO pf_vaccines VALUES(4, 'Covid Phizer', 0);


INSERT INTO pf_patientsVaccines VALUES(1, '2021/04/30', 1,	1);
INSERT INTO pf_patientsVaccines VALUES(2, '2020/07/09',	2,	1);
INSERT INTO pf_patientsVaccines VALUES(3, '2020/12/27',	3,	1);
INSERT INTO pf_patientsVaccines VALUES(4, '2021/03/14',	6,	2);
INSERT INTO pf_patientsVaccines VALUES(5, '2020/10/22',	6,	2);
INSERT INTO pf_patientsVaccines VALUES(6, '2020/12/11',	7,	2);
INSERT INTO pf_patientsVaccines VALUES(7, '2020/12/27',	9,	3);
INSERT INTO pf_patientsVaccines VALUES(8, '2021/02/01',	10,	3);
INSERT INTO pf_patientsVaccines VALUES(9, '2021/04/15',	3,	4);
INSERT INTO pf_patientsVaccines VALUES(10, '2021/03/03', 5,	4);
