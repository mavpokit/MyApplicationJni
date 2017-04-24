package com.mavpokit.myapplication;

/**
 * Created by kota on 24.04.17.
 */

public class SyncResult {
    private long book[];
    private long coll[];

    public SyncResult(long book[], long coll[]) {
        this.book = book;
        this.coll = coll;
    }

    public long[] getBook() {
        return book;
    }

    public long[] getColl() {
        return coll;
    }

    public void setBook(long book[]) {
        this.book = book;
    }

    public void setColl(long coll[]) {
        this.coll = coll;
    }
}
