package com.rentsystemapp;

import java.util.Scanner;

public class Utility {

    public static String inputChoice(String text) {

        try (Scanner myScanner = new Scanner(System.in)) {
            do {

                System.out.print(text);
                String input = myScanner.next();
                switch (input) {

                    case "1":
                    case "2":
                    case "3":
                    case "4":
                    case "5":
                    case "6":
                        return input;
                    default:
                        System.out.println("Your input is wrong.Please try again.");

                }

            } while (true);
        }

    }

    public static String inputString(String text) {

        try (Scanner myScanner = new Scanner(System.in)) {
            System.out.print(text);
            return myScanner.next();
        }

    }

    public static String inputTeleNum(String text){

        try (Scanner myScanner = new Scanner(System.in)) {
            do {

                System.out.print(text);
                String input = myScanner.next();
                //it can't deal with exception
                if(input.length() == 11 || " ".equals(input)) {
                    return input;
                }else {
                    System.out.println("Your input is wrong.Please try again.");
                }

            }while (true);
        }

    }

    public static double inputRent(String text){

        try (Scanner myScanner = new Scanner(System.in)) {
            System.out.print(text);
            //it can't deal with exception
            return myScanner.nextDouble();
        }
    }

    public static boolean inputState(String text){

        try (Scanner myScanner = new Scanner(System.in)) {
            do {

                System.out.print(text);
                String input = myScanner.next().toUpperCase();
                //it can't deal with exception
                if("YES".equals(input)){
                    return true;
                }else if("NO".equals(input)){
                    return false;
                }else {
                    System.out.println("Your input is wrong.Please try again.");
                }

            }while (true);
        }
    }

}
