package org.nsu.client.Controller;

public class Data {
    private String message;
    public boolean hasData = false;

    public synchronized void produce(String message) {
        while (hasData) {
            try {
                wait();
            } catch (InterruptedException e) {
                Thread.currentThread().interrupt();
            }
        }
        System.out.println("in produce");
        this.message = message;
        hasData = true;
        notify();
    }

    public synchronized String consume() {
        while (!hasData) {
            try {
                wait();
            } catch (InterruptedException e) {
                Thread.currentThread().interrupt();
            }
        }
        System.out.println("consumed " + message);
        hasData = false;
        notify();
        return message;
    }
}
