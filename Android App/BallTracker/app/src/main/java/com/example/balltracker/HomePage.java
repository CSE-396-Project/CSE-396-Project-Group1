package com.example.balltracker;

import androidx.appcompat.app.AppCompatActivity;

import android.annotation.SuppressLint;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.ImageButton;
import android.widget.TextView;

public class HomePage extends AppCompatActivity {

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_home_page);

        ImageButton topButton =findViewById(R.id.topButton);
        ImageButton rightButton = findViewById(R.id.rightButton);
        ImageButton leftButton = findViewById(R.id.leftButton);
        ImageButton bottomButton = findViewById(R.id.bottomButton);
        ImageButton bounceButton = findViewById(R.id.bounceButton);
        final TextView textView = findViewById(R.id.testText);

       topButton.setOnClickListener(new View.OnClickListener() {
           @Override
           public void onClick(View v) {
               textView.setText("TOP");
           }
       });

        rightButton.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                textView.setText("RIGHT");
            }
        });

        bottomButton.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                textView.setText("BOTTOM");
            }
        });

        leftButton.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                textView.setText("LEFT");
            }
        });

        bounceButton.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                textView.setText("BOUNCE THE BALL");
            }
        });
    }
}