package com.rentsystemapp;

public class mainMenu {
    private static houseService house = new houseService();
    public static void menu(){
        do{
            System.out.println("__________Rent House System__________");
            System.out.println("\t\t\t1. add house");
            System.out.println("\t\t\t2. delete house");
            System.out.println("\t\t\t3. check house");
            System.out.println("\t\t\t4. change house");
            System.out.println("\t\t\t5. house list");
            System.out.println("\t\t\t6. escape");
            System.out.println("_____________________________________");
            String Choice = Utility.inputChoice("Please input the number(1-6): ");
            switch (Choice){
                case "1":
                    house.addHouse();
                    break;
                case "2":
                    house.delHouse();
                    break;
                case "3":
                    house.checkHouse();
                    break;
                case "4":
                    house.changeHouse();
                    break;
                case "5":
                    house.listHouse();
                    break;
                case "6":
                    if(Utility.inputState("Do you really want to escape?(yes/no)")){
                        return;
                    }
                    break;
            }
        }while (true);
    }
}
