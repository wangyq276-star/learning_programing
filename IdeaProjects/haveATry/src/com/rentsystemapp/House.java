package com.rentsystemapp;

public class House {
    private int id;
    private String name;
    private String teleNumber;
    private String address;
    private double rent;
    private boolean state;

    public House(){

    }

    @Override
    public String toString(){
        return this.id + "\t\t" +
                this.name + "\t\t" +
                this.teleNumber + "\t\t" +
                this.address + "\t\t" +
                this.rent + "\t\t" +
                (this.state ? "Yes" : "No");
    }

    public int getId() {
        return id;
    }

    public void setId(int id) {
        this.id = id;
    }

    public boolean isState() {
        return state;
    }

    public void setState(boolean state) {
        this.state = state;
    }

    public double getRent() {
        return rent;
    }

    public void setRent(double rent) {
        this.rent = rent;
    }

    public String getAddress() {
        return address;
    }

    public void setAddress(String address) {
        this.address = address;
    }

    public String getTeleNumber() {
        return teleNumber;
    }

    public void setTeleNumber(String teleNumber) {
        this.teleNumber = teleNumber;
    }

    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }
}
