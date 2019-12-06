package com.scapix.chat;

import android.os.Bundle;
import android.support.design.widget.FloatingActionButton;
import android.support.design.widget.Snackbar;
import android.support.v7.app.AppCompatActivity;
import android.support.v7.widget.Toolbar;
import android.view.View;
import android.view.Menu;
import android.view.MenuItem;
import android.widget.TextView;

public class MainActivity extends AppCompatActivity {

    static {
        System.loadLibrary("chatlib");
    }

    void testScapix() {
        TextView tv = (TextView) findViewById(R.id.scapixText);

        Contact c = new Contact();
        c.name("Hello Scapix");
        tv.setText(c.name());

        Session s = new Session();
        s.addContact(c);
        s.sendMessage("aaa");
        String str = s.sendMessage3(c, "Hello Scapix ", 5);
        Contact[] cc = s.tags(new Contact[]{c, c});
        int[] ii = s.ints(new int[]{10, 20, 30});
//      s.testInt(true,true,true,0,0,0);
        tv.setText(str);

        s.connect((java.lang.String p1, Contact[] p2) -> 5);

        java.util.TreeMap<String, Contact> map = new java.util.TreeMap<>();
        map.put("one", c);
        map.put("two", c);
        java.util.TreeMap<String, Contact> map2 = s.map(map);

        java.util.TreeSet<String> set = new java.util.TreeSet<>();
        set.add("one");
        set.add("two");
        java.util.TreeSet<String> set2 = s.set(set);

        java.util.HashMap<String, Contact> hashMap = new java.util.HashMap<>();
        hashMap.put("one", c);
        hashMap.put("two", c);
        hashMap.put("three", c);
        java.util.HashMap<String, Contact> hashMap2 = s.unorderedMap(hashMap);

        java.util.HashSet<String> hashSet = new java.util.HashSet<>();
        hashSet.add("one");
        hashSet.add("two");
        hashSet.add("three");
        java.util.HashSet<String> hashSet2 = s.unorderedSet(hashSet);

        Element element = new Element();
        element.func1();
    }

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        Toolbar toolbar = findViewById(R.id.toolbar);
        setSupportActionBar(toolbar);

        FloatingActionButton fab = findViewById(R.id.fab);
        fab.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                Snackbar.make(view, "Replace with your own action", Snackbar.LENGTH_LONG)
                        .setAction("Action", null).show();
            }
        });

        testScapix();
    }

    @Override
    public boolean onCreateOptionsMenu(Menu menu) {
        // Inflate the menu; this adds items to the action bar if it is present.
        getMenuInflater().inflate(R.menu.menu_main, menu);
        return true;
    }

    @Override
    public boolean onOptionsItemSelected(MenuItem item) {
        // Handle action bar item clicks here. The action bar will
        // automatically handle clicks on the Home/Up button, so long
        // as you specify a parent activity in AndroidManifest.xml.
        int id = item.getItemId();

        //noinspection SimplifiableIfStatement
        if (id == R.id.action_settings) {
            return true;
        }

        return super.onOptionsItemSelected(item);
    }
}
