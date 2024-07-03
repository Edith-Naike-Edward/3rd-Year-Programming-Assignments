package com.example.statcalc

import android.os.Bundle
import android.widget.Button
import android.widget.EditText
import android.widget.TextView
import androidx.appcompat.app.AppCompatActivity
import kotlin.math.sqrt
import java.text.DecimalFormat
import kotlin.random.Random

class MainActivity : AppCompatActivity() {

    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        setContentView(R.layout.activity_main)

        val inputEditText: EditText = findViewById(R.id.inputEditText)
        val calculateButton: Button = findViewById(R.id.calculateButton)
        val resultTextView: TextView = findViewById(R.id.resultTextView)
        val generateButton: Button = findViewById(R.id.generateNumbersButton)

        resultTextView.text = getString(R.string.placeholder_results)

        generateButton.setOnClickListener {
            val randomNumbers = generateRandomNumbers(30)
            inputEditText.setText(randomNumbers)
        }

        calculateButton.setOnClickListener {
            val inputString = inputEditText.text.toString()
            val numbers = inputString.split(" ").mapNotNull { it.toFloatOrNull() }

            if (numbers.isEmpty() || !inputString.split(" ").all { it.isValidNumber() }) {
                resultTextView.text = getString(R.string.result_text_view)
                return@setOnClickListener
            }

            if (numbers.size > 30) {
                resultTextView.text = getString(R.string.max_numbers_message)
                return@setOnClickListener
            }

            val mean = numbers.average()
            val variance = numbers.map { (it - mean) * (it - mean) }.average()
            val stdDev = sqrt(variance)
            val range = numbers.maxOrNull()!! - numbers.minOrNull()!!

            val df = DecimalFormat("#.##")
            val meanFormatted = df.format(mean)
            val stdDevFormatted = df.format(stdDev)
            val rangeFormatted = df.format(range)

            resultTextView.text = getString(R.string.results, meanFormatted, stdDevFormatted, rangeFormatted)
        }
    }

    private fun generateRandomNumbers(count: Int): String {
        val randomNumbers = List(count) { Random.nextInt(0, 100) }
        return randomNumbers.joinToString(" ") { it.toString() }
    }

    private fun String.isValidNumber(): Boolean {
        val regex = Regex("^[+-]?\\d*\\.?\\d+$")
        return this.matches(regex)
    }
}
