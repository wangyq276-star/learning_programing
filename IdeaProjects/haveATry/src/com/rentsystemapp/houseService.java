package com.rentsystemapp;

import java.util.Scanner;

public class houseService {

    private House[] houses = new House[10];
    private int houseNum = 0;
    private int houseId = 1;

    public void addHouse(){

        do{

            System.out.println("______________Add house______________");
            houses[houseNum] = new House();
            houses[houseNum].setName(Utility.inputString("owner's name: "));
            houses[houseNum].setTeleNumber(Utility.inputTeleNum("telephone number: "));
            houses[houseNum].setAddress(Utility.inputString("address: "));
            houses[houseNum].setRent(Utility.inputRent("rent: "));
            houses[houseNum].setState(Utility.inputState("the state(yes/no): "));
            houses[houseNum].setId(houseId++);
            houseNum++;
            System.out.println("____A new house has been created_____");
            if(!Utility.inputState("Do you really want to add again?(yes/no): ")){
                return;
            }

        }while (true);

    }

    public void delHouse(){

        try (Scanner myScanner = new Scanner(System.in)) {
            int flag = -1;
            do{

                flag = -1;
                System.out.println("____________Delete house_____________");
                System.out.print("Please input the id of the house\n" +
                        "(input -1 to escape): ");
                int index = myScanner.nextInt();

                if(index == -1){
                    return;
                }

                for(int i = 0 ; i < houses.length ; i++) {
                    if (houses[i] == null || houses[i].getId() != index) {
                        continue;
                    } else {

                        flag = 1;
                        for (int j = index - 1; j < houseNum; j++) {
                            houses[j] = houses[j + 1];
                        }
                        houses[--houseNum] = null;
                    }

                }

                if(flag == -1){
                    System.out.println("The house with id " + index +" isn't found.Please try again.");
                }else {
                    System.out.println("_____the house has been deleted______");
                }

            }while (true);
        }
    }

    public void checkHouse(){

        try (Scanner myScanner = new Scanner(System.in)) {
            int flag = -1;

            do{
                flag = -1;
                System.out.println("_____________Check house_____________");
                System.out.print("Please input the id of the house\n" +
                        "(input -1 to escape): ");
                int index = myScanner.nextInt();

                if(index == -1){
                    return;
                }

                for(int i = 0 ; i < houses.length ; i++) {
                    if (houses[i] == null || houses[i].getId() != index) {
                        continue;
                    } else {
                        flag = 1;
                        System.out.println("id\t\tname\t\tnumber\t\taddress\t\trent\t\tstate");
                        System.out.println(houses[i]);
                    }

                }

                if(flag == -1) {
                    System.out.println("The house with id " + index + " isn't found.Please try again.");
                }

            }while (true);
        }
    }

    public void changeHouse(){

        try (Scanner myScanner = new Scanner(System.in)) {
            int flag = -1;

            do{

                flag = -1;
                System.out.println("____________Change house_____________");
                System.out.print("Please input the id of the house\n" +
                        "(input -1 to escape): ");
                int index = myScanner.nextInt();

                if (index == -1){
                    return;
                }

                for(int i = 0 ; i < houses.length ; i++) {
                    if (!(houses[i] == null || houses[i].getId() != index)) {

                        flag = 1;
                        String name = Utility.inputString("owner's name(" + houses[i].getName() + "): ");
                        if (!" ".equals(name)){
                            houses[i].setName(name);
                        }
                        String telephone = Utility.inputTeleNum("telephone number(" + houses[i].getTeleNumber() + "): ");
                        if (!" ".equals(telephone)){
                            houses[i].setTeleNumber(telephone);
                        }
                        String address = Utility.inputString("address(" + houses[i].getAddress() + "): ");
                        if (!" ".equals(address)){
                            houses[i].setAddress(address);
                        }
                        double rent = Utility.inputRent("rent(" + houses[i].getRent() + "): ");
                        if (!(rent == -1)){
                            houses[i].setRent(rent);
                        }
                        houses[i].setState(Utility.inputState("the state(" + houses[i].isState() + "): "));
                    }

                }

                if(flag == -1) {
                    System.out.println("The house with id " + index + " isn't found.Please try again.");
                }

            }while (true);
        }
    }

    public void listHouse(){

        System.out.println("______________house list_____________");
        System.out.println("id\t\tname\t\tnumber\t\taddress\t\trent\t\tstate");

        for (House house : houses) {
            if (house != null) System.out.println(house);
        }

    }

}
