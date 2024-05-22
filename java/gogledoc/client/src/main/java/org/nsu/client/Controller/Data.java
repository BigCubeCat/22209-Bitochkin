package org.nsu.client.Controller;

public class Data {
    private String message;
    private boolean hasData = false;

    public synchronized void produce(String message) {
        while (hasData) {
            try {
                wait();
            } catch (InterruptedException e) {
                Thread.currentThread().interrupt();
            }
        }
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
        hasData = false;
        notify();
        return message;
    }
}
